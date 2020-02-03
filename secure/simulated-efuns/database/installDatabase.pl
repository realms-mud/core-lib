#!/usr/bin/perl

print "What is the fully-qualified location of the MySQL executable?\n" .
    "For example, (/usr/mysql/bin/mysql) ";
chomp (my $mysqlCommand = <STDIN>);

print "\nWhat is the mysql (NOT your system) root password? ";
chomp (my $password = <STDIN>);

my $uuid = `python -c 'import sys,uuid; sys.stdout.write(uuid.uuid4().hex)'`;
my $mysql = "$mysqlCommand -u root -p$password";

my $dbExists = `$mysql -e "select schema_name from information_schema.schemata where schema_name = 'RealmsLib'"`;

my $createDatabase = 1;
if($dbExists ne '')
{
   print "\nIt looks like a RealmsLib database already exists! Do you want " .
       "to keep it\nor can I delete it? (type anything but 'delete' and it " .
       "will be kept.) ";
   chomp (my $keepIt = <STDIN>);

   $createDatabase = $keepIt eq 'delete';
}

if($createDatabase == 1)
{
    print "\nOK! Creating database...\n";
    my $userExists = `$mysql -e "select count(*) from mysql.user where user = 'realmslib';"`;
    $userExists = (split("\n", $userExists))[1];

    if($userExists > 0)
    {
        print "\nDeleting old user...\n";
        `$mysql -e "drop user 'realmslib'\@'localhost';"`;
    }
    if($dbExists ne '')
    {
        print "\nDeleting old database...\n";
        `$mysql -e "drop database RealmsLib;"`;
    }
    `$mysql -e "create user 'realmslib'\@'localhost' identified by '$uuid';"`;
    print "\nThe password for the user 'realmslib' is '$uuid'.\n";
    `$mysql -e "create database RealmsLib;"`;
    `$mysql -e "grant all privileges on RealmsLib.* to 'realmslib'\@'localhost';"`;
}
else
{
    print "\nOK! Using the database you have.\nNote: If the schema has " .
        "changed, you will need to reconcile these changes\nbefore this " .
        "version of the mudlib is usable.\n";
}
