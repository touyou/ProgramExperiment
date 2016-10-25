(define (fib n)
	(cond ((= 0 n) 0)
	      ((= 1 n) 1)
	      (else (+ (fib (- n 1)) (fib (- n 2))))))