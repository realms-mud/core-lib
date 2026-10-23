//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object User;
object Teacher;
object Target;
object Room;
object Katana;
object Other;
object Offhand;
string Cut = "/guilds/monk/katana/measured-cut.c";
string Edge = "/guilds/monk/katana/settled-edge.c";
string KataCommand = "kata measured cut at opponent";

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    load_object("/guilds/monk/monk.c");
    ignoreList += ({ "PrepareStudent", "ReadyKata" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Room = clone_object("/lib/environment/environment.c");
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
    Teacher = clone_object("/guilds/monk/teachers/lian.c");
    Target = clone_object("/lib/realizations/npc.c");
    Target.Name("opponent");
    Target.Race("human");
    Target.effectiveLevel(3);
    Target.setMaxHitPoints(10000);
    Katana = clone_object("/lib/items/weapon.c");
    Katana.set("blueprint", "katana");
    Katana.set("name", "katana");
    Other = clone_object("/lib/items/weapon.c");
    Other.set("blueprint", "bastard sword");
    Other.set("name", "other");
    Offhand = clone_object("/lib/items/weapon.c");
    Offhand.set("blueprint", "dagger");
    Offhand.set("name", "dagger");
    move_object(User, Room);
    move_object(Teacher, Room);
    move_object(Target, Room);
    move_object(Katana, User);
    move_object(Other, User);
    move_object(Offhand, User);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Offhand);
    destruct(Other);
    destruct(Katana);
    destruct(Target);
    destruct(Teacher);
    destruct(User);
    destruct(Room);
}

/////////////////////////////////////////////////////////////////////////////
void PrepareStudent()
{
    ExpectTrue(User.joinGuild("monk"));
    ExpectFalse(member(User.availableResearchTrees(),
        "/guilds/monk/katana.c") >= 0);
    ExpectTrue(User.learnResearchFrom(Teacher,
        "/guilds/monk/discipline/initiates-discipline.c"));
    int advancing = 1;
    while (advancing && User.guildLevel("monk") < 5)
    {
        User.addExperience(User.experienceToNextLevel("monk"), "monk");
        advancing = User.advanceLevel("monk");
    }
    ExpectEq(5, User.guildLevel("monk"));
    ExpectTrue(member(User.availableResearchTrees(),
        "/guilds/monk/katana.c") >= 0);
    ExpectTrue(User.isResearched("/guilds/monk/katana/root.c"));
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/disciplined-breath.c"));
    ExpectTrue(User.advanceRank("monk"));
}

/////////////////////////////////////////////////////////////////////////////
void ReadyKata()
{
    User.stopFight(Target);
    Target.stopFight(User);
    for (int tick = 0; tick < 4; tick++)
    {
        User.heart_beat();
    }
    User.hitPoints(10000);
    User.staminaPoints(10000);
    ExpectTrue(Target.registerAttacker(User));
    ExpectTrue(User.registerAttacker(Target));
}

/////////////////////////////////////////////////////////////////////////////
void LearningRequiresRankAndInstructionButNotEquipment()
{
    ExpectFalse(User.canResearch(Cut));
    ExpectFalse(User.learnResearchFrom(Teacher, Cut));
    PrepareStudent();
    ExpectTrue(User.canResearch(Cut));
    ExpectFalse(User.canResearch(Edge));
    ExpectFalse(User.equipmentInSlot("wielded primary"));
    int points = User.researchPoints();
    ExpectFalse(User.initiateResearch(Cut));
    ExpectTrue(User.executeCommand("lessons from lian"));
    ExpectSubStringMatch("Measured Cut", User.caughtMessage());
    ExpectSubStringMatch("Settled Edge", User.caughtMessage());
    ExpectTrue(User.executeCommand("learn measured cut from lian"));
    ExpectTrue(User.isResearched(Cut));
    ExpectEq(points - 2, User.researchPoints());
    ExpectTrue(User.canResearch(Edge));
}

/////////////////////////////////////////////////////////////////////////////
void PrimaryBlueprintIsRequiredAndTheOffhandIsUnrestricted()
{
    PrepareStudent();
    ExpectTrue(User.learnResearchFrom(Teacher, Cut));
    ReadyKata();
    int stamina = User.staminaPoints();
    ExpectFalse(User.executeCommand(KataCommand));
    ExpectFalse(load_object(Cut).execute(KataCommand, User));
    ExpectEq(Katana.query("weapon type"), Other.query("weapon type"));
    ExpectTrue(Other.equip("other"));
    ExpectFalse(User.executeCommand(KataCommand));
    ExpectFalse(load_object(Cut).execute(KataCommand, User));
    ExpectTrue(Katana.equip("katana offhand"));
    ExpectFalse(User.executeCommand(KataCommand));
    ExpectTrue(Other.unequip("other"));
    ExpectFalse(User.executeCommand(KataCommand));
    ExpectEq(stamina, User.staminaPoints());
    ExpectFalse(User.blockedByCooldown(Cut));
    ExpectEq(0, User.countObservations(([ "type":"combat.kata" ])));
    ExpectTrue(Katana.unequip("katana"));
    ExpectTrue(Katana.equip("katana"));
    ExpectTrue(Offhand.equip("dagger offhand"));
    ExpectTrue(User.executeCommand(KataCommand));
    ExpectEq(stamina - 6, User.staminaPoints());
}

/////////////////////////////////////////////////////////////////////////////
void CutUsesNormalDamageRecoveryCooldownAndWeaponContext()
{
    PrepareStudent();
    ExpectTrue(User.learnResearchFrom(Teacher, Cut));
    ExpectTrue(Katana.equip("katana"));
    ReadyKata();
    int health = Target.hitPoints();
    int stamina = User.staminaPoints();
    ExpectTrue(User.executeCommand(KataCommand));
    ExpectTrue(Target.hitPoints() < health);
    ExpectEq(stamina - 6, User.staminaPoints());
    ExpectTrue(User.blockedByCooldown(Cut));
    ExpectTrue(User.spellAction() > 0);
    mapping *observations = User.queryObservations(([
        "type":"combat.kata", "research":Cut, "qualifying opponent":1
    ]));
    ExpectEq(1, sizeof(observations));
    ExpectEq("katana", observations[0]["context"]["weapon"]);
    ExpectEq(program_name(Katana) + "#any",
        observations[0]["context"]["weapon identity"]);
    ExpectFalse(User.executeCommand(KataCommand));
    ExpectEq(stamina - 6, User.staminaPoints());
    User.stopFight(Target);
    Target.stopFight(User);
    for (int tick = 0; tick < 3; tick++)
    {
        User.heart_beat();
    }
    ExpectTrue(User.blockedByCooldown(Cut));
    ExpectFalse(User.executeCommand(KataCommand));
    User.heart_beat();
    ExpectFalse(User.blockedByCooldown(Cut));
    ExpectEq(1, User.countObservations(([ "type":"combat.kata" ])));
    ExpectTrue(Target.registerAttacker(User));
    ExpectTrue(User.registerAttacker(Target));
    ExpectTrue(User.executeCommand(KataCommand));
    ExpectEq(2, User.countObservations(([ "type":"combat.kata" ])));
}

/////////////////////////////////////////////////////////////////////////////
void WeaponSwapsAreRecheckedWithoutForgettingTheTechnique()
{
    PrepareStudent();
    ExpectTrue(User.learnResearchFrom(Teacher, Cut));
    ExpectTrue(Katana.equip("katana"));
    ReadyKata();
    ExpectTrue(User.executeCommand(KataCommand));
    ReadyKata();
    ExpectTrue(Katana.unequip("katana"));
    ExpectTrue(Other.equip("other"));
    int stamina = User.staminaPoints();
    ExpectFalse(User.executeCommand(KataCommand));
    ExpectFalse(load_object(Cut).execute(KataCommand, User));
    ExpectEq(stamina, User.staminaPoints());
    ExpectEq(1, User.countObservations(([ "type":"combat.kata" ])));
    ExpectTrue(User.isResearched(Cut));
    Other.set("blueprint", "katana");
    ExpectTrue(User.executeCommand(KataCommand));
    ExpectEq(2, User.countObservations(([ "type":"combat.kata" ])));
}

/////////////////////////////////////////////////////////////////////////////
void FollowUpRequiresCutKnowledgeAndItsBonusTracksThePrimaryBlade()
{
    PrepareStudent();
    int points = User.researchPoints();
    ExpectFalse(User.canResearch(Edge));
    ExpectFalse(User.learnResearchFrom(Teacher, Edge));
    ExpectEq(points, User.researchPoints());
    ExpectTrue(User.learnResearchFrom(Teacher, Cut));
    ExpectTrue(User.canResearch(Edge));
    ExpectFalse(User.initiateResearch(Edge));
    ExpectTrue(User.learnResearchFrom(Teacher, Edge));
    ExpectEq(points - 4, User.researchPoints());
    ExpectEq(0, User.researchBonusTo("hand and a half sword"));
    ExpectTrue(Katana.equip("katana"));
    ExpectEq(1, User.researchBonusTo("hand and a half sword"));
    ExpectTrue(Offhand.equip("dagger offhand"));
    ExpectEq(1, User.researchBonusTo("hand and a half sword"));
    ExpectTrue(Katana.unequip("katana"));
    ExpectEq(0, User.researchBonusTo("hand and a half sword"));
    ExpectTrue(Offhand.unequip("dagger"));
    ExpectTrue(Katana.equip("katana offhand"));
    ExpectTrue(Other.equip("other"));
    ExpectEq(0, User.researchBonusTo("hand and a half sword"));
    ExpectTrue(Katana.unequip("katana"));
    ExpectTrue(Other.unequip("other"));
    ExpectTrue(Katana.equip("katana"));
    ExpectEq(1, User.researchBonusTo("hand and a half sword"));
    int respect = Teacher.relationshipValue(User, "respect");
    int lessons = User.countObservations(([ "type":"training.completed" ]));
    ExpectFalse(User.learnResearchFrom(Teacher, Edge));
    ExpectEq(points - 4, User.researchPoints());
    ExpectEq(respect, Teacher.relationshipValue(User, "respect"));
    ExpectEq(lessons, User.countObservations(([
        "type":"training.completed"
    ])));
}

/////////////////////////////////////////////////////////////////////////////
void UnknownTechniquesInvalidTargetsAndLowStaminaDoNotRecordUses()
{
    PrepareStudent();
    ExpectTrue(Katana.equip("katana"));
    ReadyKata();
    int stamina = User.staminaPoints();
    ExpectFalse(User.executeCommand(KataCommand));
    ExpectFalse(load_object(Cut).execute(KataCommand, User));
    ExpectTrue(User.learnResearchFrom(Teacher, Cut));
    ExpectFalse(User.executeCommand("kata measured cut at missing"));
    ExpectEq(stamina, User.staminaPoints());
    User.staminaPoints(-User.staminaPoints());
    ExpectFalse(User.executeCommand(KataCommand));
    ExpectEq(0, User.staminaPoints());
    ExpectEq(0, User.countObservations(([ "type":"combat.kata" ])));
}

/////////////////////////////////////////////////////////////////////////////
void KatanaAndUnarmedPracticeRemainSeparate()
{
    string palm = "/guilds/monk/unarmed/measured-palm.c";
    PrepareStudent();
    ExpectTrue(User.learnResearchFrom(Teacher, palm));
    ExpectTrue(User.learnResearchFrom(Teacher, Cut));
    ReadyKata();
    ExpectTrue(User.executeCommand("kata measured palm at opponent"));
    ExpectEq(0, User.countObservations(([
        "type":"combat.kata", "research":Cut
    ])));
    ReadyKata();
    ExpectTrue(Katana.equip("katana"));
    ExpectTrue(User.executeCommand(KataCommand));
    ExpectEq(1, User.countObservations(([
        "type":"combat.kata", "research":Cut, "weapon":"katana"
    ])));
    ExpectEq(1, User.countObservations(([
        "type":"combat.kata", "research":palm
    ])));
}
