//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Wizard;
object Morech;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database.PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess.savePlayerData(database.GetWizardOfLevel("admin"));

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Morech = clone_object("/lib/tests/support/services/catchShadow.c");

    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard.restore("earl");
    Wizard.addCommands();
    Morech.beginShadow(Wizard);

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
    ExpectFalse(Wizard.executeCommand("mmore x y"), "mmore");
    ExpectFalse(Wizard.executeCommand("moree x y"), "moree");
}

/////////////////////////////////////////////////////////////////////////////
void MoreDisplaysShortFileWithoutPaging()
{
    string fileContents = "This is a file\n\nIt has 4 lines\n";
    write_file("/players/earl/stuff", fileContents);

    ExpectTrue(Wizard.executeCommand("more /players/earl/stuff"));

    ExpectEq(4, sizeof(explode(Wizard.caughtMessage(), "\n")));
    ExpectFalse(sizeof(regexp(({ Wizard.caughtMessage() }), "More? [q to quit]")));
    rm("/players/earl/stuff");
}

/////////////////////////////////////////////////////////////////////////////
void MorePagesLargeFiles()
{
    ExpectTrue(Wizard.executeCommand("more /README.md"));

    string firstPage = Wizard.caughtMessages();
    ExpectEq(22, sizeof(explode(firstPage, "\n")));
    ExpectSubStringMatch("More. .q to quit.", Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MoreFailsWhenFileDoesNotExist()
{
    ExpectEq(-1, file_size("/players/earl/x"));
    ExpectFalse(Wizard.executeCommand("more /players/earl/x"));
    ExpectSubStringMatch("The file '/players/earl/x' does not exist.", 
        Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MoreFailsWhenUserDoesNotHaveReadAccessToSource()
{
    ExpectFalse(Wizard.executeCommand("more /secure/master.c"));
    ExpectSubStringMatch("You do not have read access to '/secure/master.c'",
        Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MoreProperlyHandlesRelativePaths()
{
    copy_file("/brokenFile.c", "/players/earl/x");
    command("cd /players/earl", Wizard);

    ExpectTrue(Wizard.executeCommand("more x"));
    ExpectSubStringMatch("More. .q to quit.", Wizard.caughtMessage());
    rm("/players/earl/x");
}
