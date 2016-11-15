; http://www.geocities.jp/m_hiroi/func/abcscm28.html
(use-modules (srfi srfi-1))
(use-modules (srfi srfi-8))

(define (quick-sort ls)
 (if (null? ls)
  '()
  (let ((p (car ls)))
   (receive (a b) (partition (lambda (x) (string<? x p)) (cdr ls))
    (append (quick-sort a) (cons p (quick-sort b)))))))

(define (my-sort l)
 (quick-sort l))
