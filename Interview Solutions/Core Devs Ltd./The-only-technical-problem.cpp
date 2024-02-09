/*  You've to return a promise from the function fun
 1. double the value of 'n'
 2. create another function called innerFunction
 3. Set the default value of that function to innerValue = 5
 4. return a promise after the asynchronous task */

/* Sample Output:
   fun(5) = 15
   fun(18) = 41 */

function fun(n) {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      n *= 2;
      function innerFunction(innerValue = 5) {
        n += 5;
      }
      innerFunction();
      resolve(n);
    }, 2000);
  });
}

const promise = fun(18);

promise.then((result) => console.log(result));

