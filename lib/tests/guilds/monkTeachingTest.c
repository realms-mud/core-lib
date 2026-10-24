//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object User;
object Lian;
object Ren;
object Room;
string Intro = "/guilds/monk/discipline/initiates-discipline.c";
string Steady = "/guilds/monk/discipline/steady-practice.c";
string Recognition = "/guilds/monk/discipline/teachers-recognition.c";
string Controlled = "/guilds/monk/discipline/controlled-expenditure.c";

/////////////////////////////////////////////////////////////////////////////
void AdvanceMonkToLevel(int level)
{
    int advancing = 1;
    while (advancing && User.guildLevel("monk") < level)
    {
        User.addExperience(User.experienceToNextLevel("monk"), "monk");
        advancing = User.advanceLevel("monk");
    }
    ExpectEq(level, User.guildLevel("monk"));
}

/////////////////////////////////////////////////////////////////////////////
void PrepareRecognizedStudent()
{
    ExpectTrue(User.joinGuild("monk"));
    ExpectTrue(User.learnResearchFrom(Lian, Intro));
    AdvanceMonkToLevel(10);
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/disciplined-breath.c"));
    ExpectTrue(User.advanceRank("monk"));
    ExpectTrue(User.learnResearchFrom(Lian, Steady));
    ExpectTrue(User.learnResearchFrom(Lian, Recognition));
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    load_object("/guilds/monk/monk.c");
    ignoreList += ({ "AdvanceMonkToLevel", "PrepareRecognizedStudent" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name("student");
    User.Str(20);
    User.Int(20);
    User.Dex(20);
    User.Con(20);
    User.Wis(20);
    User.Chr(20);
    User.Race("human");
    User.colorConfiguration("none");
    Room = clone_object("/lib/environment/environment.c");
    Lian = clone_object("/guilds/monk/teachers/lian.c");
    Ren = clone_object("/guilds/monk/teachers/ren.c");
    move_object(User, Room);
    move_object(Lian, Room);
    move_object(Ren, Room);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Lian);
    destruct(Ren);
    destruct(User);
    destruct(Room);
}

/////////////////////////////////////////////////////////////////////////////
void FoundationRemainsSelfLearnableButInstructionCannotBeBypassed()
{
    ExpectTrue(User.joinGuild("monk"));
    ExpectTrue(User.canResearch(Intro));
    int points = User.researchPoints();
    ExpectFalse(User.initiateResearch(Intro));
    ExpectFalse(User.initiateResearch(Recognition));
    ExpectEq(points, User.researchPoints());
    AdvanceMonkToLevel(5);
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/disciplined-breath.c"));
}

/////////////////////////////////////////////////////////////////////////////
void EnrollmentCurriculumAndInitialLessonWorkThroughPlayerCommands()
{
    ExpectTrue(User.executeCommand("lessons from lian"));
    ExpectSubStringMatch("Initiate's Discipline", User.caughtMessage());
    ExpectSubStringMatch("Steady Practice", User.caughtMessage());
    ExpectSubStringMatch("Teacher's Recognition", User.caughtMessage());
    ExpectTrue(User.executeCommand("enroll with lian"));
    ExpectTrue(User.memberOfGuild("monk"));
    int points = User.researchPoints();
    ExpectTrue(User.executeCommand("learn initiate's discipline from lian"));
    ExpectTrue(User.isResearched(Intro));
    ExpectEq(points - 1, User.researchPoints());
    ExpectEq(1, User.researchBonusTo("unarmed"));
    ExpectEq(2, Lian.relationshipValue(User, "respect"));
    ExpectEq(1, User.countObservations(([ "type":"training.completed" ])));
    points = User.researchPoints();
    ExpectTrue(User.executeCommand("learn initiate's discipline from lian"));
    ExpectSubStringMatch("already know", User.caughtMessage());
    ExpectEq(points, User.researchPoints());
    ExpectEq(2, Lian.relationshipValue(User, "respect"));
    ExpectEq(1, User.countObservations(([ "type":"training.completed" ])));
}

/////////////////////////////////////////////////////////////////////////////
void TeachingUsesInstructorRespectRatherThanStudentOpinion()
{
    ExpectTrue(User.joinGuild("monk"));
    AdvanceMonkToLevel(10);
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/disciplined-breath.c"));
    ExpectTrue(User.advanceRank("monk"));
    ExpectFalse(User.learnResearchFrom(Lian, Steady));
    ExpectTrue(User.learnResearchFrom(Lian, Intro));
    Lian.modifyRelationship(User, "respect", -2);
    User.modifyRelationship(Lian, "respect", 50);
    int points = User.researchPoints();
    ExpectFalse(User.learnResearchFrom(Lian, Steady));
    ExpectSubStringMatch("at least 2 respect", Lian.lessonRefusal(User, Steady));
    ExpectEq(points, User.researchPoints());
    ExpectFalse(Lian.relationshipInteraction(User, "social.bow", ([])));
    ExpectFalse(Lian.relationshipInteraction(User, "gift.received", ([])));
    ExpectEq(0, Lian.relationshipValue(User, "respect"));
    Lian.modifyRelationship(User, "respect", 2);
    ExpectTrue(User.learnResearchFrom(Lian, Steady));
    ExpectEq(points - 2, User.researchPoints());
    ExpectTrue(User.learnResearchFrom(Lian, Recognition));
    ExpectEq(6, Lian.relationshipValue(User, "respect"));
}

/////////////////////////////////////////////////////////////////////////////
void AdvancedTeacherRequiresRecognitionRankAndOwnCurriculum()
{
    PrepareRecognizedStudent();
    ExpectFalse(User.learnResearchFrom(Ren, Controlled));
    AdvanceMonkToLevel(20);
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/students-awareness.c"));
    ExpectTrue(User.executeCommand("advance with lian"));
    ExpectEq("disciple", User.guildRank("monk"));
    int points = User.researchPoints();
    ExpectFalse(User.learnResearchFrom(Lian, Controlled));
    ExpectEq(points, User.researchPoints());
    User.staminaPoints(10000);
    int stamina = User.staminaPoints();
    int previousCost = stamina - User.staminaPoints(-5);
    ExpectTrue(User.executeCommand("learn controlled expenditure from ren"));
    ExpectTrue(User.isResearched(Controlled));
    ExpectEq(points - 2, User.researchPoints());
    stamina = User.staminaPoints();
    ExpectEq(previousCost - 1, stamina - User.staminaPoints(-5));
    ExpectEq(4, User.countObservations(([ "type":"training.completed" ])));
}

/////////////////////////////////////////////////////////////////////////////
void RemoteWrongTeacherAndUnknownLessonAttemptsHaveNoSideEffects()
{
    ExpectTrue(User.joinGuild("monk"));
    int points = User.researchPoints();
    move_object(Lian, this_object());
    ExpectFalse(User.learnResearchFrom(Lian, Intro));
    ExpectFalse(User.learnResearchFrom(Ren, Intro));
    ExpectTrue(User.executeCommand("learn initiate's discipline from lian"));
    ExpectSubStringMatch("no research teacher", User.caughtMessage());
    move_object(Lian, Room);
    ExpectTrue(User.executeCommand("learn nonexistent lesson from lian"));
    ExpectSubStringMatch("curriculum", User.caughtMessage());
    ExpectEq(points, User.researchPoints());
    ExpectFalse(User.isResearched(Intro));
    ExpectEq(0, User.countObservations(([ "type":"training.completed" ])));
}

/////////////////////////////////////////////////////////////////////////////
void RecognitionCannotBeSelfGrantedEvenAfterAllPrerequisitesAreMet()
{
    ExpectTrue(User.joinGuild("monk"));
    ExpectTrue(User.learnResearchFrom(Lian, Intro));
    AdvanceMonkToLevel(10);
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/disciplined-breath.c"));
    ExpectTrue(User.advanceRank("monk"));
    ExpectTrue(User.learnResearchFrom(Lian, Steady));
    ExpectTrue(User.canResearch(Recognition));
    ExpectFalse(User.initiateResearch(Recognition));
    ExpectTrue(User.learnResearchFrom(Lian, Recognition));
    ExpectFalse(User.learnResearchFrom(Lian, Recognition));
}

/////////////////////////////////////////////////////////////////////////////
void NonMembersAndDepartedMembersCannotLearnOrFarmRecognition()
{
    ExpectFalse(User.learnResearchFrom(Lian, Intro));
    PrepareRecognizedStudent();
    ExpectTrue(User.leaveGuild("monk"));
    int points = User.researchPoints();
    ExpectFalse(User.learnResearchFrom(Ren, Controlled));
    ExpectFalse(User.learnResearchFrom(Lian, Recognition));
    ExpectEq(points, User.researchPoints());
    ExpectTrue(User.isResearched(Intro));
    ExpectTrue(User.isResearched(Recognition));
}

/////////////////////////////////////////////////////////////////////////////
void SharedHallIsReachableAndContainsAllTeachers()
{
    load_object("/areas/eledhel/southern-city/monk-hall/region.c");
    object street = load_object("/areas/eledhel/southern-city/11x5.c");
    object hall = load_object("/areas/eledhel/southern-city/monk-hall/0x0.c");
    ExpectEq("/areas/eledhel/southern-city/monk-hall/0x0.c",
        street.getExitDirections()["default"]["northeast"]);
    object previousPlayer = this_player();
    set_this_player(User);
    street.enterEnvironment(User);
    ExpectTrue(command("northeast", User));
    ExpectEq(hall, environment(User));
    ExpectTrue(objectp(present("lian", hall)));
    ExpectTrue(objectp(present("iori", hall)));
    ExpectTrue(objectp(present("ren", hall)));
    ExpectTrue(objectp(present("sora", hall)));
    ExpectTrue(command("enroll with lian", User));
    ExpectTrue(command("exit", User));
    ExpectTrue(command("learn initiate's discipline from lian", User));
    ExpectTrue(User.isResearched(Intro));
    ExpectTrue(command("out", User));
    ExpectEq(street, environment(User));
    set_this_player(previousPlayer);
}
