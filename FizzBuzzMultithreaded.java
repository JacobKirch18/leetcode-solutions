//You have the four functions:
//
//printFizz that prints the word "fizz" to the console,
//printBuzz that prints the word "buzz" to the console,
//printFizzBuzz that prints the word "fizzbuzz" to the console, and
//printNumber that prints a given integer to the console.
//You are given an instance of the class FizzBuzz that has four functions: fizz, buzz, fizzbuzz and number. The same instance of FizzBuzz will be passed to four different threads:
//
//Thread A: calls fizz() that should output the word "fizz".
//Thread B: calls buzz() that should output the word "buzz".
//Thread C: calls fizzbuzz() that should output the word "fizzbuzz".
//Thread D: calls number() that should only output the integers.
//Modify the given class to output the series [1, 2, "fizz", 4, "buzz", ...] where the ith token (1-indexed) of the series is:
//
//        "fizzbuzz" if i is divisible by 3 and 5,
//        "fizz" if i is divisible by 3 and not 5,
//        "buzz" if i is divisible by 5 and not 3, or
//i if i is not divisible by 3 or 5.
//Implement the FizzBuzz class:
//
//FizzBuzz(int n) Initializes the object with the number n that represents the length of the sequence that should be printed.
//void fizz(printFizz) Calls printFizz to output "fizz".
//void buzz(printBuzz) Calls printBuzz to output "buzz".
//void fizzbuzz(printFizzBuzz) Calls printFizzBuzz to output "fizzbuzz".
//void number(printNumber) Calls printnumber to output the numbers.
//
//
//Example 1:
//
//Input: n = 15
//Output: [1,2,"fizz",4,"buzz","fizz",7,8,"fizz","buzz",11,"fizz",13,14,"fizzbuzz"]
//Example 2:
//
//Input: n = 5
//Output: [1,2,"fizz",4,"buzz"]

/*

NO MAIN PSVM TO TEST DUE TO COMPLEXITY OF IMPLEMENTING BASED ON PROVIDED CODE

*/

class FizzBuzzMultithreaded {
    private int n;
    int count;

    public FizzBuzzMultithreaded(int n) {
        this.n = n;
        this.count = 1;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        synchronized(this) {
            while (count <= n) {
                if (count % 3 == 0 && count % 5 != 0) {
                    printFizz.run();
                    count++;
                    notifyAll();
                }
                else {
                    wait();
                }
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        synchronized(this) {
            while (count <= n) {
                if (count % 3 != 0 && count % 5 == 0) {
                    printBuzz.run();
                    count++;
                    notifyAll();
                }
                else {
                    wait();
                }
            }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        synchronized(this) {
            while (count <= n) {
                if (count % 3 == 0 && count % 5 == 0) {
                    printFizzBuzz.run();
                    count++;
                    notifyAll();
                }
                else {
                    wait();
                }
            }
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        synchronized(this) {
            while (count <= n) {
                // use this block for improved memory (beats 95% runtime and 60% memory)
                if  (count % 3 == 0 || count % 5 == 0) {
                    wait();
                    continue;
                }
                printNumber.accept(count);
                count++;
                notifyAll();

                // use this block for improved runtime (beats 100% and 27% memory)
                /*
                if  (count % 3 == 0 || count % 5 == 0) {
                    wait();
                }
                else {
                    printNumber.accept(count);
                    count++;
                    notifyAll();
                }
                */
            }
        }
    }
}
