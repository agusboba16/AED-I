drop table dbo.sanciones
drop table dbo.alquileres
drop table dbo.detalle_abonos
drop table dbo.abonos
drop table dbo.socios
drop table dbo.copias
drop table dbo.peliculas
drop table dbo.nacionalidades
drop table dbo.medios
drop table dbo.categorias
go

-- Dadas las siguientes tablas:

create table dbo.categorias
(
 cod_categoria		varchar(3) 		not null primary key,
 nom_categoria		varchar(30)		not null unique,
 precio				decimal(6,2)	not null check (precio > 0),
 cant_dias_alq		tinyint			not null check (cant_dias_alq > 0) default 1,
 cant_dias_sancion	tinyint			not null check (cant_dias_sancion > 0) default 3
)
go

insert into dbo.categorias
values ('A', 'CATEGORIA A', 5.00, 1, 5)
insert into dbo.categorias
values ('B', 'CATEGORIA B', 4.00, 2, 4)
insert into dbo.categorias
values ('C', 'CATEGORIA C', 3.00, 3, 3)
insert into dbo.categorias
values ('D', 'CATEGORIA D', 2.00, 4, 1)
go

create table dbo.nacionalidades
(
 nacionalidad		varchar(30)	not null primary key
)
go

insert into dbo.nacionalidades
values ('ARGENTINA')
insert into dbo.nacionalidades
values ('ESPAÑOLA')
insert into dbo.nacionalidades
values ('ITALIANA')
go

create table dbo.peliculas
(
 nro_pelicula		integer			not null primary key,
 titulo				varchar(100)	not null,
 nacionalidad		varchar(30)		not null references dbo.nacionalidades,
 cod_categoria		varchar(3)		not null references dbo.categorias,
 resumen			varchar(4000)	null
)
go

insert into dbo.peliculas
values (1, 'PELICULA 1', 'ARGENTINA', 'A', NULL)
insert into dbo.peliculas
values (2, 'PELICULA 2', 'ARGENTINA', 'A', NULL)
insert into dbo.peliculas
values (3, 'PELICULA 3', 'ESPAÑOLA', 'B', NULL)
insert into dbo.peliculas
values (4, 'PELICULA 4', 'ITALIANA', 'B', NULL)
insert into dbo.peliculas
values (5, 'PELICULA 5', 'ITALIANA', 'C', NULL)
go

create table dbo.medios
(
 cod_medio		varchar(3)	not null primary key,
 nom_medio		varchar(30)	not null unique
)
go

insert into dbo.medios
values ('DVD', 'DVD')
insert into dbo.medios
values ('VHS', 'VHS')
go

create table dbo.copias
(
 nro_pelicula	integer		not null references dbo.peliculas,
 nro_copia		smallint	not null,
 estado			char(1)		not null check (estado in ('B','M','R')) default 'B',
 cod_medio		varchar(3)	not null references dbo.medios,
 primary key (nro_pelicula, nro_copia)
)
go

insert into dbo.copias
values (1, 1, 'B', 'DVD')
insert into dbo.copias
values (1, 2, 'B', 'DVD')
insert into dbo.copias
values (2, 1, 'B', 'VHS')
insert into dbo.copias
values (2, 2, 'B', 'DVD')
insert into dbo.copias
values (2, 3, 'B', 'DVD')
insert into dbo.copias
values (3, 1, 'R', 'VHS')
insert into dbo.copias
values (4, 1, 'R', 'VHS')
insert into dbo.copias
values (5, 1, 'R', 'VHS')
go

create table dbo.socios
(
 nro_socio			integer			not null primary key,
 apellido			varchar(40)		not null,
 nombre				varchar(40)		not null,
 tipo_documento		varchar(3)		not null,
 nro_documento		integer			not null,
 direccion			varchar(100)	not null,
 telefonos			varchar(100)	not null,
 unique (tipo_documento, nro_documento)
)
go

insert into dbo.socios
values (1, 'APELLIDO SOCIO 1', 'NOMBRE SOCIO 1', 'DNI', 12345678, 'AV. SAN MARTIN 125',	'3513182838')
insert into dbo.socios
values (2, 'APELLIDO SOCIO 2', 'NOMBRE SOCIO 2', 'DNI', 23456789, 'AV. BELGRANO 1245',	'3513142338')
insert into dbo.socios
values (3, 'APELLIDO SOCIO 3', 'NOMBRE SOCIO 3', 'DNI', 34567890, 'SAN JUAN 3464',		'3513186754')
insert into dbo.socios
values (4, 'APELLIDO SOCIO 4', 'NOMBRE SOCIO 4', 'DNI', 45678901, 'GENERAL PAZ 433',	'3513245773')
insert into dbo.socios
values (5, 'APELLIDO SOCIO 5', 'NOMBRE SOCIO 5', 'DNI', 56789012, 'RODRIGUEZ PEÑA 333',	'3517644352')
go


create table dbo.abonos
(
 nro_abono		integer			not null primary key,
 nro_socio		integer			not null references dbo.socios,
 fecha_compra	smalldatetime	not null,
 importe		decimal(6,2)	not null,
 fecha_vto		smalldatetime	not null
)
go

insert into dbo.abonos
values (1, 1, '01 mar 2007 0:00', 10.00, '25 may 2007 0:00')
insert into dbo.abonos
values (2, 1, '01 jun 2007 0:00', 10.00, '30 sep 2007 0:00')
insert into dbo.abonos
values (3, 2, '01 may 2007 0:00', 12.00, '31 jul 2007 0:00')
insert into dbo.abonos
values (4, 2, '01 jul 2007 0:00', 12.00, '31 oct 2007 0:00')
insert into dbo.abonos
values (5, 3, '01 mar 2007 0:00', 13.00, '25 dec 2007 0:00')
insert into dbo.abonos
values (6, 4, '01 mar 2007 0:00', 14.00, '31 dec 2007 0:00')
go

create table dbo.detalle_abonos
(
 nro_abono		integer		not null references dbo.abonos,
 cod_categoria	varchar(3)	not null references dbo.categorias,
 cant_copias	tinyint		not null check (cant_copias > 0),
 primary key (nro_abono, cod_categoria)
)
go

insert into dbo.detalle_abonos
values (1, 'A', 10)
insert into dbo.detalle_abonos
values (1, 'B', 5)
insert into dbo.detalle_abonos
values (2, 'A', 20)
insert into dbo.detalle_abonos
values (2, 'C', 10)
insert into dbo.detalle_abonos
values (3, 'A', 30)
insert into dbo.detalle_abonos
values (3, 'B', 15)
insert into dbo.detalle_abonos
values (4, 'B', 40)
insert into dbo.detalle_abonos
values (4, 'C', 20)
insert into dbo.detalle_abonos
values (5, 'B', 50)
insert into dbo.detalle_abonos
values (5, 'C', 25)
insert into dbo.detalle_abonos
values (6, 'C', 60)
go

create table dbo.alquileres
(
 nro_alquiler	integer			not null primary key,
 nro_socio		integer			not null references dbo.socios,
 fecha_alquiler	smalldatetime	not null,
 nro_pelicula	integer			not null,
 nro_copia		smallint		not null,
 nro_abono		integer			not null,
 cod_categoria	varchar(3)		not null,
 fecha_a_dev	smalldatetime	not null,
 fecha_dev		smalldatetime	null,
 foreign key (nro_pelicula, nro_copia)  references dbo.copias,
 foreign key (nro_abono, cod_categoria) references dbo.detalle_abonos
)
go

insert into dbo.alquileres
values (1, 1, '01 may 2007 0:00', 1, 1, 1, 'A', '02 may 2007 0:00', null)
insert into dbo.alquileres
values (2, 1, '01 jun 2007 0:00', 1, 1, 1, 'A', '02 jun 2007 0:00', null)
insert into dbo.alquileres
values (3, 1, '01 jul 2007 0:00', 1, 1, 2, 'A', '02 jul 2007 0:00', null)
insert into dbo.alquileres
values (4, 1, '01 jul 2007 0:00', 1, 1, 2, 'C', '02 jul 2007 0:00', null)
insert into dbo.alquileres
values (5, 2, '01 may 2007 0:00', 1, 1, 3, 'A', '02 may 2007 0:00', null)
insert into dbo.alquileres
values (6, 2, '01 may 2007 0:00', 1, 1, 3, 'A', '02 may 2007 0:00', null)
insert into dbo.alquileres
values (7, 3, '01 may 2007 0:00', 1, 1, 5, 'B', '02 may 2007 0:00', null)
insert into dbo.alquileres
values (8, 3, '01 may 2007 0:00', 1, 1, 5, 'C', '02 may 2007 0:00', null)
insert into dbo.alquileres
values (9, 3, '01 may 2007 0:00', 1, 1, 5, 'C', '02 may 2007 0:00', null)
insert into dbo.alquileres
values (10, 3, '01 may 2007 0:00', 1, 1, 5, 'C', '02 may 2007 0:00', null)
go

create table dbo.sanciones
(
 nro_alquiler	integer			not null,
 nro_sancion	smallint		not null,
 fecha_inicio	date			not null,
 fecha_fin		date			not null,
 primary key (nro_alquiler, nro_sancion),
 foreign key (nro_alquiler) references dbo.alquileres
)
go

/* CONSIGNA:

La tabla sanciones es redundante puesto que toda la información se puede obtener de la base de datos, por lo tanto debemos programar 
triggers para propagar las actualizaciones. 
La regla para el registro de una sanción es la siguiente:
"Para cada alquiler devuelto con retraso se debe registrar una sanción con fecha_inicio igual a la fecha de devolucion del alquiler y fecha_fin igual 
a la fecha_inicio más los días de sanción (tomados de la información de la categoría de película)"

1. Determinar los triggers necesarios (tabla, operación y columnas involucradas (en el caso de update)) (40)

----------------------------------------------------------------------------------------------------------------------
-- TABLA       |    INSERT 					 |	  DELETE			|	  UPDATE									 |
---------------------------------------------------------------------------------------------------------------------|
-- alquileres   |   controlar si se inserta	 |				 		|	si la fecha_dev se actualiza				 |
			    |   la fecha_dev como null   |						|	y es menor que la fecha a dev o es null		 |
				|   entonces no se inserta	 |						|	entonces se debe borrar la san				 |
				|   una sancion,			 |						|	cion, si la fecha_dev es > a				 |
				|   si inserta una fecha_dev |						|	la fecha a dev entonces se agre			     |
				|   mayor a la fecha de alqui|						|	ga una sancion							     |
				|   ler entonces se agrega 	 |						|											     |
				|	sancion					 |						|												 |
--              |							 |		                |											     |
---------------------------------------------------------------------------------------------------------
-- categorias   |	-----------------		 |			---         |  controlar si se cambia la cant de dias		 |
--              |							 |                      |  de sancion entonces actualizar las sanciones  |
				|							 |				        |  por categoria								





------------------------------------------------------------------------------


tabla	   |		Insert				|	delete	|  update        
----------------------------------------------------------------------------------------
alquileres | controlar que si inserta	|			|- controlar que si se actualiza
		   | fecha devolucion no null   |	-		|fecha devolucion a = a null o 
		   | si es > a la fecha a dev	|			|o < a fecha a dev
		   | debe poner sancion			|			|se debe borre la sancion.
		   |							|			|- controlar si se actualiza 
		   |							|			|fecha de dev > a fecha a dev
		   |							|			|se inserta sancion
----------------------------------------------------------------------------------------
categorias |							|			|-si se cambia la cant. de dias
		   |			-			    |	-		| cambiar la cantidad de dias de
		   |							|			| las sanciones segun categoria
		   |							|			|
		   |							|			|
		   |							|			|
		   |							|			|
----------------------------------------------------------------------------------------














2. Programar los triggers (60)
*/


create or alter trigger 