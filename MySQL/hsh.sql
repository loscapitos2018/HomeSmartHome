-- phpMyAdmin SQL Dump
-- version 4.6.6
-- https://www.phpmyadmin.net/
--
-- Servidor: localhost
-- Tiempo de generación: 15-09-2018 a las 23:07:37
-- Versión del servidor: 5.7.17-log
-- Versión de PHP: 5.6.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `hsh`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `climatizador`
--

CREATE TABLE `climatizador` (
  `id_cuarto` int(2) NOT NULL,
  `estado` char(2) NOT NULL,
  `fechora` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `id_usuario` int(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `luces`
--

CREATE TABLE `luces` (
  `id_cuarto` int(2) NOT NULL,
  `estado` char(2) NOT NULL,
  `fechora` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `id_usuario` int(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `luces`
--

INSERT INTO `luces` (`id_cuarto`, `estado`, `fechora`, `id_usuario`) VALUES
(1, '1', '2018-09-15 16:25:07', 1);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `luzctr`
--

CREATE TABLE `luzctr` (
  `id_cuarto` int(11) NOT NULL,
  `fech_hor` datetime NOT NULL,
  `estado` char(2) NOT NULL,
  `id_usuario` int(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `puertas`
--

CREATE TABLE `puertas` (
  `id_cuarto` int(11) NOT NULL,
  `estado` char(2) NOT NULL,
  `fechora` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `id_usuario` int(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `puertasctr`
--

CREATE TABLE `puertasctr` (
  `id_cuarto` int(2) NOT NULL,
  `fechora` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `estado` char(2) NOT NULL,
  `id_usuario` int(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `teminter`
--

CREATE TABLE `teminter` (
  `id_tempint` int(2) NOT NULL,
  `id_cuarto` int(2) NOT NULL,
  `lectura` int(2) NOT NULL,
  `fechora` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tempctr`
--

CREATE TABLE `tempctr` (
  `id_consumo` int(2) NOT NULL,
  `id_cuarto` int(2) NOT NULL,
  `lectura_h` int(2) NOT NULL,
  `fecha_temp` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `temperatura`
--

CREATE TABLE `temperatura` (
  `id_cuarto` int(2) NOT NULL,
  `estado` char(2) NOT NULL,
  `fechora` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `id_usuario` int(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tempset`
--

CREATE TABLE `tempset` (
  `id_cuarto` int(2) NOT NULL,
  `htemp` int(2) NOT NULL,
  `ltemp` int(2) NOT NULL,
  `id_usuario` int(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `climatizador`
--
ALTER TABLE `climatizador`
  ADD PRIMARY KEY (`id_cuarto`);

--
-- Indices de la tabla `luces`
--
ALTER TABLE `luces`
  ADD PRIMARY KEY (`id_cuarto`);

--
-- Indices de la tabla `luzctr`
--
ALTER TABLE `luzctr`
  ADD PRIMARY KEY (`id_cuarto`);

--
-- Indices de la tabla `puertas`
--
ALTER TABLE `puertas`
  ADD PRIMARY KEY (`id_cuarto`);

--
-- Indices de la tabla `puertasctr`
--
ALTER TABLE `puertasctr`
  ADD PRIMARY KEY (`id_cuarto`);

--
-- Indices de la tabla `teminter`
--
ALTER TABLE `teminter`
  ADD PRIMARY KEY (`id_cuarto`);

--
-- Indices de la tabla `tempctr`
--
ALTER TABLE `tempctr`
  ADD PRIMARY KEY (`id_cuarto`);

--
-- Indices de la tabla `temperatura`
--
ALTER TABLE `temperatura`
  ADD PRIMARY KEY (`id_cuarto`);

--
-- Indices de la tabla `tempset`
--
ALTER TABLE `tempset`
  ADD PRIMARY KEY (`id_cuarto`);

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `luzctr`
--
ALTER TABLE `luzctr`
  ADD CONSTRAINT `luzctr_ibfk_1` FOREIGN KEY (`id_cuarto`) REFERENCES `luces` (`id_cuarto`) ON UPDATE CASCADE;

--
-- Filtros para la tabla `puertasctr`
--
ALTER TABLE `puertasctr`
  ADD CONSTRAINT `puertasctr_ibfk_1` FOREIGN KEY (`id_cuarto`) REFERENCES `puertas` (`id_cuarto`) ON UPDATE CASCADE;

--
-- Filtros para la tabla `tempctr`
--
ALTER TABLE `tempctr`
  ADD CONSTRAINT `tempctr_ibfk_1` FOREIGN KEY (`id_cuarto`) REFERENCES `climatizador` (`id_cuarto`) ON UPDATE CASCADE;

--
-- Filtros para la tabla `tempset`
--
ALTER TABLE `tempset`
  ADD CONSTRAINT `tempset_ibfk_1` FOREIGN KEY (`id_cuarto`) REFERENCES `climatizador` (`id_cuarto`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
