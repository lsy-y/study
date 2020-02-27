
```
1 <?php
2 var_dump("admin"==0);  //true
3 var_dump("1admin"==1); //true
4 var_dump("admin1"==1) //false
5 var_dump("admin1"==0) //true
6 var_dump("0e123456"=="0e4456789"); //true 
7 ?>
```

php中有两种比较的符号==与===

=== 在进行比较的时候，会先判断两种字符串的类型是否相等，再比较

== 在进行比较的时候，会先将字符串类型转化成相同，再比较

# 函数

##  preg_replace

preg_replace — 执行正则表达式的搜索和替换 

搜索subject中匹配pattern的部分， 
以replacement进行替换。



##  die

die（）函数输出一条消息，并退出当前脚本。

# 出现乱码

## 在html中

```php+HTML
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
```

在<head></head>中加入上面这句

## html和php混编

```php+HTML
<?php
header("content-type:text/html;charset=utf-8");         //设置编码
 
?>
```

## 纯php

```php
<?php
header("content-type:text/html;charset=utf-8");         //设置编码
?>
```

## php+Mysql

这个除了按照第三种所说的操作之外，还要在你的数据查询/修改/增加之前加入数据库编码。而且，值得注意的是，这里的UTF8和之前的不一样，中间是没有横线的。

```php
<?php
   mysql_query('SET NAMES UTF8');
   //接下来的就是查出数据或者修改，增加
   ?>
```

# php文件上传

自己写的脚本

```php+HTML
<!DOCTYPE html>
<html>
<head>	
	<meta http-equiv="Content-Type" content="text/html;charset=utf8"/>
	<title>文件上传</title>
</head>
<body>
	<h2>UPLOAD FILE</h2>
	<form enctype="multipart/form-data" action="" method="post">
		<input type="file" name="myfile" size=20>
		<input type="submit" name="upload" value="上传" size=10>
	</form>
<?php
	if(isset($_POST['upload'])){
		if($_FILES['myfile']['error']>0)
			echo "错误:".$_FILES['myfile']['type'];
		else{
			$tmp_filename=$_FILES['myfile']['tmp_name'];
			$filename=$_FILES['myfile']['name'];
			$dir="../WWW/upload/";
			if(is_uploaded_file($tmp_filename)){
				if(move_uploaded_file($tmp_filename,"$dir.$filename")){
					echo "上传文件成功!";
					echo "文件大小为：".($_FILES['myfile']['size']/1024)."kb";
				}
				else "上传文件失败！！";
			}
		}
		
	}
?>
</body>
</html>
```

非常简单，没有过滤，什么都能传

#  php+Mysql

```php+HTML

<!DOCTYPE html>
<html>
<head>
	<title>Finding User</title>
</head>
<body>
	<h2>Finding Users from mysql database.</h2>
	<form action="php&Mysql.php" method="post">
		Fill user's number:
		<input type="text" name="id" size="20"> <br>
		<input type="submit" name="submit" value="Find">
	</form>
</body>
</html>

```
里面的php&Mysql.php就是下面的文件

```php+HTML
<!DOCTYPE html>
<html>
<head>
	<title>user found</title>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
</head>
<body>
<?php
	$usernumber=$_POST['id'];
	$db=mysqli_connect("localhost","root","root",'test');
	if(!$db){
		die("无法建立");
	}
	$q1="SELECT * FROM student WHERE id ='".$usernumber."'";//SQL查询语句
		$result1 = mysqli_query($db,$q1);//执行SQL语句
		$rownum = mysqli_num_rows($result1);//获取查询结果集中的记录数
		for($i=0;$i<$rownum;$i++)
		{
			$row=mysqli_fetch_assoc($result1);//从数组结果集中获取信息，关联数组形式返回
			$infoarr_bks=array('id'=>$row['id'],"名字"=>$row['usename'],'密码'=>$row['password']);
			print_r($infoarr_bks);//输出数组
		}
		mysqli_free_result($result1);
	
?>
</body>
</html>
	
```

## mysqli_connect



主要连接的函数**mysqli_connect('server','username','password')**

server就是Mysql的名字，username就是用户名，password就是密码