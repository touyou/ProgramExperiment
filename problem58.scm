(define (fix f)
  (lambda (x) ((f (fix f)) x)))

(define (u f x)
 (if (= x 0)
  1
  (* x (f (- x 1)))))

(define (fact5 n)
 ((fix (u * n)) 1))
