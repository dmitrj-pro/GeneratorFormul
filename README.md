# GeneratorFormul

Работа библиотеки проверена на компиляторах: 
	g++ (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609
	g++.exe (tdm-1) 4.9.2


Данная библиотека основана на наследовании. Структура наследования:

Gen - Интерфейс генератора

	-| Constant - класс константы

	-| Master - клас, знающий о других класах и структуре наследования. Отвечает за генерирование самих выражений


	RecursiveGen - интерфейс рекурсивного генератора

		-| Parenthesis - генерирует выражение в скобках

		iLFGen - интерфейс рекурсивного генератора, способного генерировать левые/правые выражения

			-| Divide - класс, генерирующий деление

			-| Minus - класс, генерирующий вычитание

			-| Multiple - генерирует умножение

			-| Sum - генерирует сумму

		Variable - интерфейс переменных

			-| ConstVariable - клас константной переменной

			-| UnExistsVariable - Клас неиницилизированной переменной 


Для добавление новых возможностей нужно реализовать клас одного из бозового интерфейса и добавить его в Master.

В файле iGen.h объявлены макросы:

	SysType - тип, используемый генератором для входных данных

	ControlOverflow - контролировать ли переполнение данного типа. Если макрос отключен, то переполнение не контролируется


Использование:

#include "MasterGen.h" - подключаем заголовочный файл

Generator::Collection::Master master; - создаем переменную генератора

master.SetValue("Name",34); - создаем переменную Name со значением 34

master.SetValue("UnKnow"); - создаем неизвестную переменную UnKnow.

string res=master(55); - получаем выражение для 55

	
Для компиляции библиотеки под Linux:

	1) из терминала перейти в папку Generator

	2) Выполнить: 

		mv TEST.cpp TEST.cpp6 - переместим файл с тестами

		g++ -fpic -c -std=c++11 *.cpp Gens/*.cpp - компилируем все c++ файлы

		g++ --share *.o -o libgenerator.so - собираем библиотеку

		sudo cp libgenerator.so /lib - копируем библиотеку в папку для библиотек

		rm *.cpp Gens/*.cpp - удаляем все cpp файлы, если нужно

		mv TEST.cpp6 TEST.cpp - восстанавливаем файл с тестом

	3) Для компилирования файла с тестами требуется менеджер потоков из первого задания, поскольку для быстроты тесты запускаются многопоточно, особенно тест на оптимизацию.

	Однако из TEST.cpp можно убрать макрос LINUX, тогда менеджер потоков не нужен

		g++ TEST.cpp -o run -std=c++11 libgenerator.so собираем TEST, указывая, где искать отсутствующую реализацию

	4) ./run запускаем

LibGen.mkv - пример компиляции и генерирования выражений (без звука)
	
