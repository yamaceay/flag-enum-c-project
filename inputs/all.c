typedef enum restaurant {
  arrived = 1,
  waiting = 2,
  assigned = 4,
  ordered = 8,
  prepared = 16,
  eating = 32,
  paid = 64,
  leaving = 128
} restaurant;

typedef enum tcp_connection {
  syn = 1,
  ack = 2,
  fin = 4
} tcp_connection;

typedef enum font {
  script = 1,
  italic = 2,
  big = 4
} font;

