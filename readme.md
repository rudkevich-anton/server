# Запуск сервера
./main -f base.txt -p 33333 -e error.txt

# Чтобы нормально генерировался pdf из tex

\usepackage[english,russian]{babel}
\usepackage[T2A]{fontenc}
\usepackage[utf8]{inputenc}

# Чтобы заработало модульное тестирование
Правой кнопкой по проекту 
	Settings -> Compiler -> Include Paths: /usr/include/UnitTest++
	Settings -> Linker -> Libraries Search Paths: /usr/lib/x86_64-linux-gnu/
	Settings -> Linker -> Libraries: libUnitTest++.so



на ubuntu 22.04
dpkg -L libunittest++2 - не та библиотека
dpkg -L libunittest++-dev <- вот та что нужна

поменять пути в соответствии с инструкцией 

[инструкцией](https://wiki.codelite.org/pmwiki.php/Main/UnitTestPP)
