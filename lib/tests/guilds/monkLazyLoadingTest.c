//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object *Teachers = ({});
object User;
object Room;
string *Disciplines = ({ "unarmed", "katana", "bludgeon", "pure-chi",
    "mana-shield", "paired-swords", "odachi", "archery", "kama", "claw" });

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
void ColdGuildAndTeacherRegistrationDoNotCompileTheCombatCatalog()
{
    ExpectFalse(find_object("/guilds/monk/monk.c"),
        "Run this cold-start fixture before other Monk fixtures");
    int *usage = rusage();
    int before = usage[0] + usage[1];
    load_object("/guilds/monk/monk.c");
    usage = rusage();
    int elapsed = usage[0] + usage[1] - before;
    debug_message(sprintf("Monk lazy profile: cold guild: %dms CPU\n",
        elapsed), 0x5);
    ExpectTrue(elapsed <= 200, "Cold guild registration <= 200ms CPU");
    foreach(string discipline in ({ "discipline" }) + Disciplines)
    {
        ExpectFalse(find_object("/guilds/monk/" + discipline + ".c"),
            discipline + " tree is not loaded by guild registration");
    }
    usage = rusage();
    before = usage[0] + usage[1];
    foreach(string name in ({ "lian", "ren", "sora", "iori" }))
    {
        int *teacherUsage = rusage();
        int teacherBefore = teacherUsage[0] + teacherUsage[1];
        Teachers += ({ clone_object("/guilds/monk/teachers/" + name + ".c") });
        teacherUsage = rusage();
        int teacherElapsed = teacherUsage[0] + teacherUsage[1] - teacherBefore;
        debug_message(sprintf("Monk lazy profile: first %s: %dms CPU\n",
            name, teacherElapsed), 0x5);
        ExpectTrue(teacherElapsed <= 200, name + " creation <= 200ms CPU");
    }
    usage = rusage();
    elapsed = usage[0] + usage[1] - before;
    debug_message(sprintf("Monk lazy profile: four cold teachers: "
        "%dms CPU\n", elapsed), 0x5);
    foreach(string discipline in ({ "discipline" }) + Disciplines)
    {
        ExpectFalse(find_object("/guilds/monk/" + discipline + ".c"),
            discipline + " tree is not loaded by teacher creation");
    }
    int lessons = 0;
    foreach(string discipline in Disciplines)
    {
        string treePath = "/guilds/monk/" + discipline + ".c";
        string *paths = getService("lessons")->lessonPaths(treePath);
        ExpectEq(40, sizeof(paths), discipline);
        foreach(string path in paths)
        {
            ExpectFalse(find_object(path), path + " remains unloaded");
            lessons++;
        }
    }
    ExpectEq(400, lessons);
    ExpectEq(7, sizeof(Teachers[0].teachableResearch()));
    ExpectEq(201, sizeof(Teachers[1].teachableResearch()));
    ExpectEq(160, sizeof(Teachers[2].teachableResearch()));
    ExpectEq(40, sizeof(Teachers[3].teachableResearch()));
    ExpectFalse(Teachers[1].teachesResearch(
        "/guilds/monk/unarmed/measured-palm.c"));
    ExpectFalse(Teachers[3].teachesResearch("/guilds/monk/archery/root.c"));
    foreach(string discipline in Disciplines)
    {
        foreach(string path in getService("lessons")->lessonPaths(
            "/guilds/monk/" + discipline + ".c"))
        {
            ExpectFalse(find_object(path), path + " membership is path-only");
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void LearningOneLessonDoesNotCompileUnrelatedLessons()
{
    Room = clone_object("/lib/environment/environment.c");
    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name("lazyinitiate");
    User.Race("human");
    object teacher = clone_object("/guilds/monk/teachers/lian.c");
    Teachers += ({ teacher });
    move_object(teacher, Room);
    move_object(User, Room);
    ExpectTrue(User.joinGuild("monk"));
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/disciplined-breath.c"));
    ExpectTrue(User.learnResearchFrom(teacher,
        "/guilds/monk/discipline/initiates-discipline.c"));
    string palm = "/guilds/monk/unarmed/measured-palm.c";
    ExpectTrue(User.learnResearchFrom(teacher, palm));
    ExpectTrue(find_object(palm));
    foreach(string discipline in Disciplines)
    {
        foreach(string path in getService("lessons")->lessonPaths(
            "/guilds/monk/" + discipline + ".c") - ({ palm }))
        {
            ExpectFalse(find_object(path), path + " is unrelated to Palm");
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void RemoteRefusalDoesNotLoadTheRequestedLesson()
{
    Room = clone_object("/lib/environment/environment.c");
    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    object teacher = clone_object("/guilds/monk/teachers/ren.c");
    Teachers += ({ teacher });
    move_object(teacher, Room);
    string lesson = "/guilds/monk/unarmed/driving-elbow.c";
    ExpectFalse(find_object(lesson));
    ExpectEq("You must be in the same room as your teacher.",
        teacher.lessonRefusal(User, lesson));
    ExpectFalse(find_object(lesson));
}

/////////////////////////////////////////////////////////////////////////////
void NamedLookupLoadsOnlyTheRequestedTeachersCatalogAndReusesNames()
{
    object teacher = clone_object("/guilds/monk/teachers/ren.c");
    Teachers += ({ teacher });
    string *paths = teacher.teachableResearch();
    int *usage = rusage();
    int before = usage[0] + usage[1];
    ExpectEq(({ "/guilds/monk/bludgeon/measured-impact.c" }),
        getService("lessons")->matchingLessons(paths, "Measured Impact"));
    usage = rusage();
    debug_message(sprintf("Monk lazy profile: first named Ren lookup: "
        "%dms CPU\n", usage[0] + usage[1] - before), 0x5);
    foreach(string discipline in ({ "paired-swords", "odachi", "archery",
        "kama", "claw" }))
    {
        foreach(string path in getService("lessons")->lessonPaths(
            "/guilds/monk/" + discipline + ".c"))
        {
            ExpectFalse(find_object(path), path + " is not in Ren's catalog");
        }
    }
    usage = rusage();
    before = usage[0] + usage[1];
    ExpectEq(({ "/guilds/monk/bludgeon/measured-impact.c" }),
        getService("lessons")->matchingLessons(paths, "MEASURED IMPACT"));
    usage = rusage();
    int elapsed = usage[0] + usage[1] - before;
    debug_message(sprintf("Monk lazy profile: cached named Ren lookup: "
        "%dms CPU\n", elapsed), 0x5);
    ExpectTrue(elapsed <= 200, "Warm named lookup <= 200ms CPU");
}
