(define (btree-top t)
 (cdar t))
(define (btree-left t)
 (car t))
(define (btree-right t)
 (cddr t))

(define (btree-single val)
 (list btree-empty val btree-empty))

(define (btree-empty)
  ;; 空木を返す。
  (list)
  )
(define (btree-null? t)
  ;; 二分木`t'が空かどうかを真偽値で返す。
  (null? t)
  )
(define (btree-insert key val t)
  ;; 文字列`key'をキーとして文字列`val'を二分探索木`t'に挿入し、その木を返す。
  (cond
   ((btree-null? t)
    (btree-single (cons key val)))
   ((string>? (btree-top t) key)
    (list (btree-insert key val (btree-left t)) (btree-top t) (btree-right t)))
   (else
    (list (btree-left t) (btree-top t) (btree-insert key val (btree-right t))))
   )
  )
(define (btree-delete key t)
  ;; 文字列`key'をキーとする項目を、二分探索木`t'から削除し、その木を返す。
  (cond
   ((btree-null? t) t)
   ((string=? (btree-top t) key)
    (list (btree-left t) (btree-top (btree-right t)) 
  )
(define (btree-search key t)
  ;; 文字列`key'をキーとして二分探索木`t'を検索し、キーとデータのペアを返す。
  ;; 見つからない場合は、#fを返す。
  (cond
   ((btree-null? t) #f)
   ((string=? (btree-top t) key) (btree-top t))
   ((string>? (btree-top t) key) (btree-search key (btree-left t)))
   (else (btree-search key (btree-right t))))
  )
(let ((t (btree-empty)))
  (define (input->string x)
    (cond
     ((symbol? x) (symbol->string x))
     ((number? x) (number->string x))
     ((string? x) x)
     (else #f)))
  (define (main-loop t)
    (let ((cmd (read)))
      (cond
       ((equal? cmd 'insert)
        (let* ((key (input->string (read)))
               (val (input->string (read))))
          (main-loop (btree-insert key val t))))
       ((equal? cmd 'delete)
        (let* ((key (input->string (read))))
          (main-loop (btree-delete key t))))
       ((equal? cmd 'search)
        (let* ((key (input->string (read)))
               (entry (btree-search key t)))
          (if (not entry)
              (display "(not found)\n")
              (begin
                (display (cdr entry))
                (newline)))
          (main-loop t)))
       ((or (equal? cmd 'quit) (eof-object? cmd))
        #t)
       (else
        (display "(unknown command)\n")
        (main-loop t)))))
  (main-loop t))
