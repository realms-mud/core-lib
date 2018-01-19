//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private string Fail = "[0;31m[  FAILED  ][0m ";

private string LibPrefix = "/lib";
private string TestPrefix = "/lib/tests";
private string *DirectoriesToSearch = ({
    "commands",
    "commands/player",
    "commands/soul",
    "commands/wizard",
    "core",
    "dictionaries",
    "environment",
    "instances",
    "instances/research",
    "instances/traits",
    "items",
    "modules",
    "modules/combat",
    "modules/combat/attacks",
    "modules/guilds",
    "modules/quests",
    "modules/research",
    "modules/traits",
    "realizations"
});

private int Failure;

/////////////////////////////////////////////////////////////////////////////
void delayedExecute(string fileToTest)
{
    int cur = (int)call_other(fileToTest, "executeTests");
    Failure ||= cur;
    if (Failure)
    {
        write("Overall test execution: " + Fail + "\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
private void executeTests()
{
    int delay = 1;

    foreach(string subDir in DirectoriesToSearch)
    {
        string *files = get_dir(sprintf("%s/%s/*.c", LibPrefix, subDir));
        foreach(string file in files)
        {
            string testFile = regreplace(file, "\\.c", "Test.c");
            string fileToTest = sprintf("%s/%s/%s", TestPrefix, subDir, testFile);
            if (file_size(fileToTest) > 0)
            {
                call_out("delayedExecute", delay / 4, fileToTest);
            }
            else
            {
                Failure = 1;
                write(sprintf("%s Missing test for %s/%s/%s\n", Fail, LibPrefix, subDir, file));
            }
        }
        delay++;
    }
}


