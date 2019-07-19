#lang scheme
;funzione hanoi
(define (hanoi n source destination support)
  (if(= n 1) 
     ;(printf "base hanoi Muovi il disco da ~a a ~a~n" source destination)
     (with-output-to-file "(yourPath)output_scheme.txt" #:exists 'append
       (lambda () (printf "~a,~a~n" source destination)))
     ;(printf "~a,~a~n" source destination)
     (begin 
            (hanoi (- n 1) source support destination)
            ;(printf "Muovi il disco da ~a a ~a~n" source destination)
            (hanoi 1 source destination support)
            (hanoi (- n 1) support destination source)
     )
  )
)

(define (hanoi_bicolore cont n source destination support)
  (if (> cont n)
      (splitta (/ n 2) destination source support)
      (begin
        (hanoi (+ cont 2) destination source support)
        (hanoi_bicolore (+ cont 2) n destination source support)
      )
  )
)

(define (splitta n source destination support)	
  (if (= n 1)
     ;(printf "base splitta Muovi il disco da ~a a ~a~n" source destination)
      (hanoi 1 source destination support)
     (begin
       (hanoi2 (- n 1) source support destination)
       ;(printf "Muovi il disco da ~a a ~a~n" source destination)
       (hanoi 1 source destination support)
       (hanoi2 (- n 1) support source destination)
       (splitta (- n 1) source destination support)
     )
  )
)

(define (hanoi2 n source destination support)
  (if (= n 1)
     (begin
      ;(printf "Muovi il disco da ~a a ~a~n" source destination)
      ;(printf "Muovi il disco da ~a a ~a~n" source destination)
       (hanoi 1 source destination support)
       (hanoi 1 source destination support)
     )
     (begin 
       (hanoi2 (- n 1) source support destination)
       ;(printf "Muovi il disco da ~a a ~a~n" source destination)
       ;(printf "Muovi il disco da ~a a ~a~n" source destination)
       (hanoi 1 source destination support)
       (hanoi 1 source destination support)
       (hanoi2 (- n 1) support destination source)
     )
  )
)
