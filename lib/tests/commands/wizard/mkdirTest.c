//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Wizard;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database->PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess->savePlayerData(database->GetWizardOfLevel("admin"));

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard->restore("earl");
    Wizard->addCommands();
    setUsers(({ Wizard }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Wizard);
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Wizard->executeCommand("mmkdir"), "mmkdir");
    ExpectFalse(Wizard->executeCommand("mkdirr"), "mkdirr");
}

/////////////////////////////////////////////////////////////////////////////
void MkdirCreatesDirectory()
{
    ExpectFalse(file_size("/players/earl/newDir") == -2);
    ExpectTrue(Wizard->executeCommand("mkdir /players/earl/newDir"));
    ExpectTrue(file_size("/players/earl/newDir") == -2);
    rmdir("/players/earl/newDir");
}

/////////////////////////////////////////////////////////////////////////////
void MkdirFailsIfUserDoesNotHaveWriteAccess()
{
    ExpectFalse(file_size("/secure/newDir") == -2);
    ExpectFalse(Wizard->executeCommand("mkdir /secure/newDir"));
}

/////////////////////////////////////////////////////////////////////////////
void MkdirFailsIfParentDirectoryDoesNotExist()
{
    ExpectFalse(file_size("/players/earl/newDir/blah") == -2);
    ExpectFalse(Wizard->executeCommand("mkdir /players/earl/newDir/blah"));
}

/////////////////////////////////////////////////////////////////////////////
void MkdirFailsIfDirectoryAlreadyExists()
{
    ExpectTrue(file_size("/players/earl") == -2);
    ExpectFalse(Wizard->executeCommand("mkdir /players/earl"));
}

/////////////////////////////////////////////////////////////////////////////
void MkdirFailsIfFileWithNameAlreadyExists()
{
    ExpectTrue(file_size("/players/earl/blah") > -1);
    ExpectFalse(Wizard->executeCommand("mkdir /players/earl/blah"));
}

/////////////////////////////////////////////////////////////////////////////
void MkdirCreatesRelativePathDirectory()
{
    ExpectTrue(Wizard->executeCommand("cd /players/earl"));
    ExpectFalse(file_size("/players/earl/newDir") == -2);
    ExpectTrue(Wizard->executeCommand("mkdir newDir"));
    ExpectTrue(file_size("/players/earl/newDir") == -2);
    rmdir("/players/earl/newDir");
}

/////////////////////////////////////////////////////////////////////////////
void MkdirCreatesHomeDirectorySubdirs()
{
    ExpectFalse(file_size("/players/earl/newDir") == -2);
    ExpectTrue(Wizard->executeCommand("mkdir ~/newDir"));
    ExpectTrue(file_size("/players/earl/newDir") == -2);
    rmdir("/players/earl/newDir");
}

/////////////////////////////////////////////////////////////////////////////
void MkdirCreatesSpecifiedHomeDirectorySubdirs()
{
    ExpectFalse(file_size("/players/earl/newDir") == -2);
    ExpectTrue(Wizard->executeCommand("mkdir ~earl/newDir"));
    ExpectTrue(file_size("/players/earl/newDir") == -2);
    rmdir("/players/earl/newDir");
}
