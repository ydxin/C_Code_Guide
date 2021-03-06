USE [master]
GO
/****** Object:  Database [tb_person]    Script Date: 2019.9.20 12:28:04 ******/
CREATE DATABASE [tb_person]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'tb_person', FILENAME = N'E:\Application\SQL_SERVER\Microsoft SQL Server\MSSQL12.MSSQLSERVER\MSSQL\DATA\tb_person.mdf' , SIZE = 5120KB , MAXSIZE = UNLIMITED, FILEGROWTH = 1024KB )
 LOG ON 
( NAME = N'tb_person_log', FILENAME = N'E:\Application\SQL_SERVER\Microsoft SQL Server\MSSQL12.MSSQLSERVER\MSSQL\DATA\tb_person_log.ldf' , SIZE = 2048KB , MAXSIZE = 2048GB , FILEGROWTH = 10%)
GO
ALTER DATABASE [tb_person] SET COMPATIBILITY_LEVEL = 120
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [tb_person].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [tb_person] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [tb_person] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [tb_person] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [tb_person] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [tb_person] SET ARITHABORT OFF 
GO
ALTER DATABASE [tb_person] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [tb_person] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [tb_person] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [tb_person] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [tb_person] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [tb_person] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [tb_person] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [tb_person] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [tb_person] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [tb_person] SET  DISABLE_BROKER 
GO
ALTER DATABASE [tb_person] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [tb_person] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [tb_person] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [tb_person] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [tb_person] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [tb_person] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [tb_person] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [tb_person] SET RECOVERY SIMPLE 
GO
ALTER DATABASE [tb_person] SET  MULTI_USER 
GO
ALTER DATABASE [tb_person] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [tb_person] SET DB_CHAINING OFF 
GO
ALTER DATABASE [tb_person] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [tb_person] SET TARGET_RECOVERY_TIME = 0 SECONDS 
GO
ALTER DATABASE [tb_person] SET DELAYED_DURABILITY = DISABLED 
GO
ALTER DATABASE [tb_person] SET  READ_WRITE 
GO
