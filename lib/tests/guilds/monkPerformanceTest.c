//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/support/guilds/monkTrialFixture.c";

object User;
object Room;
object *Teachers = ({});
mapping Timings = ([]);

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "ReportTiming", "TeachMonkTrialLesson",
        "CompleteMonkUpperTrial" });
}

/////////////////////////////////////////////////////////////////////////////
void ReportTiming(string stage, int *started, int cpu)
{
    int *usage = rusage();
    int *finished = utime();
    Timings[stage] = usage[0] + usage[1] - cpu;
    debug_message(sprintf("Monk profile: %s: %dms CPU, %dms elapsed\n",
        stage, Timings[stage], (finished[0] - started[0]) * 1000 +
        (finished[1] - started[1]) / 1000), 0x5);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    foreach(object actor in Teachers + ({ User, Room }))
    {
        if (objectp(actor))
        {
            destruct(actor);
        }
    }
    Teachers = ({});
}

/////////////////////////////////////////////////////////////////////////////
void ProfileGuildLoadingTeacherSetupAndFullCurriculum()
{
    int *usage = rusage();
    int cpu = usage[0] + usage[1];
    int *started = utime();
    debug_message(sprintf("Monk profile: guild already loaded: %d\n",
        objectp(find_object("/guilds/monk/monk.c"))), 0x5);
    load_object("/guilds/monk/monk.c");
    ReportTiming("guild lookup", started, cpu);

    foreach(string name in ({ "lian", "ren", "sora", "iori" }))
    {
        usage = rusage();
        cpu = usage[0] + usage[1];
        started = utime();
        Teachers += ({ clone_object("/guilds/monk/teachers/" + name + ".c") });
        ReportTiming("first " + name, started, cpu);
    }
    foreach(object teacher in Teachers)
    {
        destruct(teacher);
    }
    Teachers = ({});

    usage = rusage();
    cpu = usage[0] + usage[1];
    started = utime();
    Room = clone_object("/lib/environment/environment.c");
    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name("profile");
    User.Race("human");
    User.colorConfiguration("none");
    move_object(User, Room);
    foreach(string name in ({ "lian", "ren", "sora", "iori" }))
    {
        object teacher = clone_object("/guilds/monk/teachers/" + name + ".c");
        Teachers += ({ teacher });
        move_object(teacher, Room);
    }
    ReportTiming("warm fixture setup", started, cpu);

    destruct(User);
    usage = rusage();
    cpu = usage[0] + usage[1];
    started = utime();
    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name("profile");
    User.Race("human");
    User.colorConfiguration("none");
    move_object(User, Room);
    ReportTiming("warm student setup with existing teachers", started, cpu);
    ExpectTrue(Timings["warm student setup with existing teachers"] <= 200);

    usage = rusage();
    cpu = usage[0] + usage[1];
    started = utime();
    ExpectTrue(User.joinGuild("monk"));
    User.addResearchPoints(1000);
    ExpectTrue(User.learnResearchFrom(Teachers[0],
        "/guilds/monk/discipline/initiates-discipline.c"));
    string *foundations = ({ "disciplined-breath", "students-awareness",
        "disciples-insight", "adepts-focus", "inner-discipline",
        "mastery-of-fundamentals" });
    for (int index = 0; index < sizeof(foundations); index++)
    {
        while (User.guildLevel("monk") < MonkPromotionLevels[index])
        {
            User.addExperience(User.experienceToNextLevel("monk"), "monk");
            ExpectTrue(User.advanceLevel("monk"));
        }
        ExpectTrue(User.initiateResearch("/guilds/monk/discipline/" +
            foundations[index] + ".c"));
        if (index == 2)
        {
            for (int use = 0; use < 10; use++)
            {
                ExpectTrue(mappingp(User.recordObservation(([
                    "type":"combat.kata",
                    "context":([
                        "research":"/guilds/monk/unarmed/measured-palm.c",
                        "qualifying opponent":1
                    ])
                ]), 1)));
            }
            ExpectTrue(User.learnResearchFrom(Teachers[1],
                "/guilds/monk/discipline/adepts-trial.c"));
        }
        if (index >= 3)
        {
            CompleteMonkUpperTrial(User, Teachers[0], Teachers[1], index - 3);
        }
        ExpectTrue(User.advanceRank("monk"));
        if (!index)
        {
            ExpectTrue(User.learnResearchFrom(Teachers[0],
                "/guilds/monk/discipline/steady-practice.c"));
            ExpectTrue(User.learnResearchFrom(Teachers[0],
                "/guilds/monk/discipline/teachers-recognition.c"));
        }
    }
    ReportTiming("full promotion lifecycle", started, cpu);

    usage = rusage();
    cpu = usage[0] + usage[1];
    started = utime();
    foreach(string discipline in ({ "unarmed", "katana", "bludgeon",
        "pure-chi", "mana-shield", "paired-swords", "odachi", "archery",
        "kama", "claw" }))
    {
        object tree = getService("research")->researchTree(
            "/guilds/monk/" + discipline + ".c");
        foreach(object item in m_indices(tree.getFlattenedResearchTree()))
        {
            TeachMonkTrialLesson(User, Teachers, program_name(item));
        }
    }
    ReportTiming("learn all 400 lessons", started, cpu);
}
