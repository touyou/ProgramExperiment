(let ((init-list (list)))
  (define (input->string x)
    (cond
     ((symbol? x) (symbol->string x))
     ((number? x) (number->string x))
     ((string? x) x)
     (else #f)))
  (define (read-as-list l)
    (let ((data (input->string (read))))
      (if data (read-as-list (cons data l)) l)))
  (define (list-display l)
    (cond ((not (null? l))
           (display (car l)) (newline) (list-display (cdr l)))))
  (list-display (my-sort (read-as-list init-list))))
