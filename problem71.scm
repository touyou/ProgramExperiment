; marge sort

(define (filter predicate ls)
 (cond ((null? ls) '())
  ((predicate (car ls))
   (cons (car ls) (filter predicate (cdr ls))))
  (else
   (filter predicate (cdr ls)))))

(define (my-sort li)
 (if (null? li)
  ()
  (let ((piv (car li))
        (back (cdr li))
        (lit (filter (lambda (x) (string>? piv x)) back))
        (big (filter (lambda (x) (string<? piv x)) back))
        (eql (filter (lambda (x) (string=? piv x)) back)))
   (my-sort (cons lit (cons piv (cons eql big)))))))
