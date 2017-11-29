//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Wizard;
object Room;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database->PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess->savePlayerData(database->GetWizardOfLevel("creator"));

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Room = clone_object("/lib/environment/room.c");

    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard->restore("earl");
    Wizard->addCommands();
    setUsers(({ Wizard }));

    move_object(Wizard, Room);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Wizard);
    destruct(Room);
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Wizard->executeCommand("ccc"), "ccc");
    ExpectFalse(Wizard->executeCommand("accelerate"), "accelerate");
}

/////////////////////////////////////////////////////////////////////////////
void CCOfExistingProgramReturnsOneWhenSuccessfullyBuilds()
{
    ExpectEq(1, Wizard->executeCommand("cc /lib/modules/combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CCOfNonexistantFileReturnsFalse()
{
    ExpectEq(0, Wizard->executeCommand("cc /lib/include/inventory"));
}

/////////////////////////////////////////////////////////////////////////////
void CCOfDirectoryWithoutRecurseFlagReturnsFalse()
{
    ExpectEq(0, Wizard->executeCommand("cc /lib/modules"));
}

/////////////////////////////////////////////////////////////////////////////
void CCOfDirectoryRecursivelyBuilds()
{
    ExpectEq(6, Wizard->executeCommand("cc -r /obj"));
}

/////////////////////////////////////////////////////////////////////////////
void RecursiveCCWithoutTargetRecursivelyBuildsPWD()
{
    Wizard->pwd("/lib/core");
    ExpectEq(8, Wizard->executeCommand("cc -r"));
}

/////////////////////////////////////////////////////////////////////////////
void CCOfDirectoryWherePermissionDeniedDoesNotBuild()
{
    ExpectEq(0, Wizard->executeCommand("cc -r /secure"));
}

/////////////////////////////////////////////////////////////////////////////
void CCOfFileWherePermissionDeniedDoesNotBuild()
{
    ExpectEq(0, Wizard->executeCommand("cc /secure/player/player.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CCOfInvalidFileDoesNotBuild()
{
    ExpectEq(0, Wizard->executeCommand("cc /badfile.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CCOfProgramWithRelativePathSuccessfullyBuilds()
{
    Wizard->pwd("/lib/modules");
    ExpectEq(1, Wizard->executeCommand("cc combat.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CCOfProgramWithRelativeButNoDotCSuccessfullyBuilds()
{
    Wizard->pwd("/lib/modules");
    ExpectEq(1, Wizard->executeCommand("cc combat"));
}

/////////////////////////////////////////////////////////////////////////////
void CCWithoutParamsCompilesEnvironment()
{
    ExpectEq(1, Wizard->executeCommand("cc"));
}
