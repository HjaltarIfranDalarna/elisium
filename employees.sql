PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE employees (id integer primary key,firstname text, lastname text, email text);
INSERT INTO "employees" VALUES(1,'Slava','Berlioz','berlioz@gmail.com');
INSERT INTO "employees" VALUES(2,'Michael','Shavlyuk','shavlyuk@mail.ru');
INSERT INTO "employees" VALUES(3,'Andrew','Andruxovich','adnruxovish@gmail.com');
INSERT INTO "employees" VALUES(4,'Andrew','Moshko','moshko@gmail.com');
INSERT INTO "employees" VALUES(5,'Alex','Pykavy','buhgalter@gmail.com');
INSERT INTO "employees" VALUES(6,'Alexander','Pistoletov','mrHelicopter@gmail.com');
INSERT INTO "employees" VALUES(7,'Zinaida','Davydova','Kudelya@gmail.com');
INSERT INTO "employees" VALUES(8,'Euhenia','Davydova','jenechka@gmail.com');
COMMIT;
