(define (fib x y n)
 (if (= n 0)
  y
  (fib y (+ x y) (- n 1))))

(define (fib2 n)
 (let ((y 1)
       (x 1))
  (while (not (= n 0))
   (set! y (+ x y))
   (set! x y)
   (- n 1))
  y))
