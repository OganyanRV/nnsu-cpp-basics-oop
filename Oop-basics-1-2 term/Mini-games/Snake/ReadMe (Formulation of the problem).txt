Rus:
Разработать систему классов и реализовать с ее помощью игру «Змейка».
Требования (правила).
· Играет один игрок (человек), управляющий «змейкой».
· Игра идет на прямоугольном поле N x M клеток. Поле ограничено «стенами» так что вместе со стенами размер поля – (N + 2) x (M + 2) клеток.
· При старте игры змейка имеет длину 5 клеток, форму в виде горизонтального отрезка и располагается в произвольном месте поля, не пересекая и не касаясь стен.
· При старте игры «голова» змейки располагается слева, «хвост» справа. Голова змейки окрашена в цвет, отличный от цвета остальных клеток ее тела.
· При старте игры в произвольной клетке поля (не совпадающей с клетками, занятыми змейкой) возникает «пища».
· При запуске игрового процесса (по специальной команде или автоматически при старте игры) змейка начинает автоматическое движение влево с некоторой заданной скоростью.
· Движение заключается в том, что за каждый такт голова змейки перемещается на одну клетку в текущем направлении движения, а клетка, в которой располагался хвост, становится пустой.
· Игрок может сменить направление движения змейки с помощью клавиш-«стрелок» (вверх, вниз, влево, вправо).
· Если на текущем такте движения голова змейки должна будет занять клетку стены или клетку, которая уже занята любой из клеток ее тела, игра прекращается и считается проигранной.
· Задача игрока вырастить змейку до заданного при старте игрового процесса размера. Змейка вырастает в длину на одну клетку (с хвоста) при каждом поглощении пищи, т.е. в тот момент, когда ее голова на очередном такте движения занимает клетку, в которой расположена пища. На этом же такте в произвольном месте игрового поля (не совпадающей с клетками, занятыми змейкой) снова появляется пища.
· Если змейка выросла до заданной при старте игрового процесса длины, игра считается выигранной.
Eng: (Google Translator)
Made a class system and implement the game "Snake" with its help.
Requirements (rules).
· One player (person) is playing, managing the “snake”.
· The game is played on a rectangular field of N x M cells. The field is limited by "walls" so that together with the walls the size of the field is (N + 2) x (M + 2) cells.
· At the start of the game, the snake has a length of 5 cells, a shape in the form of a horizontal segment and is located in an arbitrary place of the field, without crossing and not touching the walls.
· At the start of the game, the "head" of the snake is located on the left, the "tail" on the right. The head of the snake is painted in a color different from the color of the remaining cells of its body.
· At the start of the game in an arbitrary cell of the field (which does not coincide with the cells occupied by the snake), "food" occurs.
· When starting the game process (by a special command or automatically at the start of the game), the snake starts automatically moving to the left at a given speed.
· The movement consists in the fact that for each measure the head of the snake moves one cell in the current direction of movement, and the cell in which the tail was located becomes empty.
· The player can change the direction of the snake using the arrow keys (up, down, left, right).
· If the snake’s head must occupy a wall cell or a cell that is already occupied by any of the cells in its body at the current measure of movement, the game stops and is considered lost.
· The player’s task is to grow the snake to the size specified at the start of the game process. The snake grows in length by one cell (from the tail) with each absorption of food, i.e. at the moment when her head at the next step of movement occupies the cell in which the food is located. At the same measure in an arbitrary place on the playing field (which does not coincide with the cells occupied by the snake), food appears again.
· If the snake has grown to the length specified at the start of the game process, the game is considered to be won.
