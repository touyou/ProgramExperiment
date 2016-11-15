; splay heap
; heap sort

(define (heap-empty) (list))
(define heap-null? null?)
(define heap-top cadr)
(define heap-left car)
(define heap-right caddr)
(define (heap-single n)
    (if (string? n)
     '(heap-empty n heap-empty)
     (heap-empty)))
(define (new-heap n h1 h2) '(h1 n h2))

(define (partition h piv)
  (if (heap-null? h)
    '(heap-empty heap-empty)
    (cond ((string>? (heap-top h) piv)
            (let ((a (heap-left h))
                  (b (heap-right h))
                  (a1 (heap-left a))
                  (a2 (heap-right a))
                  (y (heap-top a)))
             (cond ((heap-null? a) '(heap-empty h))
                   ((string>? y piv)
                        (let ((rec (partition a1 piv)))
                            '((car rec) (new-heap y (cdr rec) (new-heap (heap-top h) a2 b)))))
                   (else
                        (let ((rec (partition a2 piv)))
                            '((new-heap y a1 (car rec)) (new-heap (heap-top h) (cdr rec) b)))))))
            (else (let ((a (heap-left h))
                        (b (heap-right h))
                        (b1 (heap-left b))
                        (b2 (heap-right b))
                        (y (heap-top b)))
                    (cond ((heap-null? b) '(h heap-empty))
                      ((string>? y piv)
                        (let ((rec (partition b1 piv)))
                          '((new-heap (heap-top h) a (car rec)) (new-heap y (cdr rec) b2))))
                      (else
                        (let ((rec (partition b2 piv)))
                            '((new-heap y (new-heap (heap-top h) a b1) (car rec)) (cdr rec))))))))))

(define (heap-insert h n)
 (let ((rec (partition h n)))
    (new-heap n (car rec) (cdr rec))))

(define (findMin h)
 (let ((a (heap-left h))
       (x (heap-top h))
       (b (heap-right h)))
  (if (heap-null? a)
   x
   (findMin a))))

(define (deleteMin h)
 (let ((a (heap-left h))
       (b (heap-right h))
       (x (heap-top)))
  (if (heap-null? a)
   b
   (if (heap-null? (heap-left a))
    (new-heap x (heap-right a) b)
    (new-heap (heap-top a) (deleteMin a) (new-heap x (heap-right a) b))))))

(define (make-sorted a h)
 (if (heap-null? h)
  a
  (make-sorted (cons a (findMin h)) (deleteMin h))))

(define (my-sort-iter h l)
 (if (null? l)
  h
  (my-sort-iter (heap-insert h (car l)) (cdr l))))

(define (my-sort l)
 (make-sorted (list) (my-sort-iter (heap-single (car l)) (cdr l))))
