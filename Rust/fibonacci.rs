struct Fibonacci {
    curr: u64,
    prev: u64,
}

impl Iterator for Fibonacci {
    type Item = u64;
    
    fn next(&mut self) -> Option<u64> {
        let temp = self.curr;
        self.curr = self.curr + self.prev;
        self.prev = temp;
        
        Some(temp)
    }
}

fn fibonacci() -> Fibonacci {
    Fibonacci { curr: 1, prev: 1 }
}

fn main() {
    println!("{}", fibonacci()
             .take_while(|&x| x < 4000000)
             .filter(|x| x % 2 == 0)
             .fold(0, |a,b| a + b));
}

