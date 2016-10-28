(define (my-foldl op acc l)
  (if (null? l)
      acc
      (my-foldl op (op (car l) acc) (cdr l))))

(define (ope elem key)
 (if (equal? key (car elem))
  elem
  key))

(define (my-assoc2 key dict)
 (let ((res (my-foldl ope key dict)))
  (if (equal? key res)
   #f
   res)))
