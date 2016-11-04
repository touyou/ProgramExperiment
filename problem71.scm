; marge sort

(define (filter predicate ls)
 (cond ((null? ls) '())
  ((predicate (car ls))
   (cons (car ls) (filter predicate (cdr ls))))
  (else
   (filter predicate (cdr ls)))))

(define (my-fold op init l)
 (if (null? l)
  init
  (my-fold op (op (car l) init) (cdr l))))

(define (make-new-list a b c)
 (my-fold cons (my-fold cons (my-fold cons '() a) b) c))

(define (my-sort li)
 (if (null? (car li))
  (car li)
  (let ((lit (filter (lambda (x) (string>? (car li) x)) (cdr li)))
        (big (filter (lambda (x) (string<? (car li) x)) (cdr li)))
        (eql (filter (lambda (x) (string=? (car li) x)) li)))
   (my-sort (make-new-list lit eql big)))))
