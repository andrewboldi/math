use std::fs::File;
use std::io::{self, Write};
use std::sync::{Arc, Mutex};
use std::thread;

fn sieve_segment(segment_start: u64, segment_end: u64, sieve: &mut Vec<bool>, file: &mut File) -> io::Result<()> {
    let sqrt_end = (segment_end as f64).sqrt() as u64;
    for i in 2..=sqrt_end {
        if sieve[i as usize] {
            let mut j = i * i;
            while j <= segment_end {
                sieve[j as usize] = false;
                j += i;
            }
        }
    }
    for i in (segment_start..=segment_end).step_by(2) {
        if sieve[i as usize] {
            writeln!(file, "{}", i)?;
        }
    }
    Ok(())
}

fn main() -> io::Result<()> {
    let limit = 1_000_000_000_000; // 1 trillion
    let filename = "trillion_primes.txt";

    let file = File::create(filename)?;

    let num_threads = num_cpus::get();
    let chunk_size = (limit + 1) / num_threads as u64;

    let mut handles = vec![];
    let sieve = Arc::new(Mutex::new(vec![true; (chunk_size + 1) as usize]));

    for i in 0..num_threads {
        let sieve_clone = Arc::clone(&sieve);
        let mut file_clone = file.try_clone()?;
        let segment_start = i as u64 * chunk_size;
        let segment_end = if i == num_threads - 1 {
            limit
        } else {
            (i as u64 + 1) * chunk_size
        };
        handles.push(thread::spawn(move || {
            let mut sieve = sieve_clone.lock().unwrap();
            sieve_segment(segment_start, segment_end, &mut sieve, &mut file_clone).unwrap();
        }));
    }

    for handle in handles {
        handle.join().unwrap();
    }

    Ok(())
}

