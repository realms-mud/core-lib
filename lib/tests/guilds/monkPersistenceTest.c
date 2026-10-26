//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/support/guilds/monkTrialFixture.c";
#include "/lib/include/inventory.h"

object Player;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "PrepareRecognizedDisciple", "RoundTripBladeStudy",
        "TeachMonkTrialLesson", "CompleteMonkUpperTrial" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    setRestoreCaller(this_object());
    load_object("/guilds/monk/monk.c");
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    validateTestDatabase();
    object authentication = clone_object(
        "/lib/modules/secure/dataServices/authenticationDataService.c");
    authentication.saveUser("gorthaur", "gorthaur", "127.0.0.1");
    destruct(authentication);
    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    mapping data = database.Gorthaur();
    data["guilds"] = ([]);
    dataAccess.savePlayerData(data);
    destruct(dataAccess);
    destruct(database);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void MembershipRankResearchAndAwardsSurviveSaveDestroyRestore()
{
    string breath = "/guilds/monk/discipline/disciplined-breath.c";
    ExpectTrue(Player.joinGuild("monk"));
    int advancing = 1;
    while (advancing && Player.guildLevel("monk") < 10)
    {
        Player.addExperience(Player.experienceToNextLevel("monk"), "monk");
        advancing = Player.advanceLevel("monk");
    }
    ExpectEq(10, Player.guildLevel("monk"));
    ExpectTrue(Player.initiateResearch(breath));
    ExpectTrue(Player.advanceRank("monk"));
    int points = Player.researchPoints();
    int skills = Player.AvailableSkillPoints();
    int hitPoints = Player.maxHitPoints();
    Player.save();
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    ExpectTrue(Player.memberOfGuild("monk"));
    ExpectEq(10, Player.guildLevel("monk"));
    ExpectEq("student", Player.guildRank("monk"));
    ExpectTrue(Player.isResearched(breath));
    ExpectTrue(member(Player.availableResearchTrees(),
        "/guilds/monk/discipline.c") >= 0);
    ExpectEq(points, Player.researchPoints());
    ExpectEq(skills, Player.AvailableSkillPoints());
    ExpectEq(hitPoints, Player.maxHitPoints());
    ExpectFalse(Player.joinGuild("monk"));
    ExpectFalse(Player.advanceRank("monk"));
    ExpectFalse(Player.initiateResearch(breath));
    ExpectEq(points, Player.researchPoints());
}

/////////////////////////////////////////////////////////////////////////////
void VoluntaryDepartureAndRetainedKnowledgeSurviveRestore()
{
    ExpectTrue(Player.joinGuild("monk"));
    ExpectTrue(Player.leaveGuild("monk"));
    Player.save();
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    ExpectFalse(Player.memberOfGuild("monk"));
    ExpectTrue(Player.isResearched("/guilds/monk/discipline/root.c"));
    ExpectTrue(Player.isAnathema("monk"));
    ExpectFalse(Player.joinGuild("monk"));
}

/////////////////////////////////////////////////////////////////////////////
void TaughtKnowledgeAndInstructorRespectSurviveRestoreWithoutRepeatingAwards()
{
    string lesson = "/guilds/monk/discipline/initiates-discipline.c";
    object room = clone_object("/lib/environment/environment.c");
    object teacher = clone_object("/guilds/monk/teachers/lian.c");
    move_object(Player, room);
    move_object(teacher, room);
    ExpectTrue(Player.joinGuild("monk"));
    ExpectTrue(Player.learnResearchFrom(teacher, lesson));
    int points = Player.researchPoints();
    Player.save();
    destruct(teacher);
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    teacher = clone_object("/guilds/monk/teachers/lian.c");
    move_object(Player, room);
    move_object(teacher, room);
    ExpectTrue(Player.isResearched(lesson));
    ExpectEq(2, teacher.relationshipValue(Player, "respect"));
    ExpectEq(1, Player.countObservations(([ "type":"training.completed" ])));
    ExpectFalse(Player.learnResearchFrom(teacher, lesson));
    ExpectEq(points, Player.researchPoints());
    ExpectEq(2, teacher.relationshipValue(Player, "respect"));
    ExpectTrue(Player.leaveGuild("monk"));
    Player.save();
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    ExpectTrue(Player.isResearched(lesson));
    ExpectFalse(Player.memberOfGuild("monk"));
    ExpectEq(points, Player.researchPoints());
    destruct(teacher);
    destruct(room);
}

/////////////////////////////////////////////////////////////////////////////
void TeacherRequiredTimedLessonResumesWithoutItsTeacherAfterRestore()
{
    string lesson =
        "/lib/tests/support/research/teacherRequiredTimedResearch.c";
    object room = clone_object("/lib/environment/environment.c");
    object teacher = clone_object("/lib/tests/support/research/testTeacher.c");
    move_object(Player, room);
    move_object(teacher, room);
    string identity = teacher.relationshipIdentity();
    ExpectFalse(Player.initiateResearch(lesson));
    ExpectTrue(Player.learnResearchFrom(teacher, lesson));
    Player.heart_beat();
    Player.heart_beat();
    ExpectFalse(Player.isResearched(lesson));
    Player.save();
    destruct(teacher);
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    ExpectFalse(Player.initiateResearch(lesson));
    Player.heart_beat();
    ExpectTrue(Player.isResearched(lesson));
    ExpectEq(2, Player.relationshipFrom(identity)["dimensions"]["respect"]);
    ExpectEq(1, Player.countObservations(([ "type":"training.completed" ])));
    Player.heart_beat();
    ExpectEq(1, Player.countObservations(([ "type":"training.completed" ])));
    destruct(room);
}

/////////////////////////////////////////////////////////////////////////////
void CombatPracticeThresholdSurvivesRestoreAndUnlocksTheTaughtFollowUp()
{
    string palm = "/guilds/monk/unarmed/measured-palm.c";
    string recovery = "/guilds/monk/unarmed/balanced-recovery.c";
    mapping criteria = ([
        "type":"combat.kata",
        "research":palm,
        "qualifying opponent":1
    ]);
    object room = clone_object("/lib/environment/environment.c");
    object teacher = clone_object("/guilds/monk/teachers/lian.c");
    object foe = clone_object("/lib/realizations/npc.c");
    foe.Name("opponent");
    foe.effectiveLevel(3);
    foe.setMaxHitPoints(10000);
    move_object(Player, room);
    move_object(teacher, room);
    move_object(foe, room);
    ExpectTrue(Player.joinGuild("monk"));
    ExpectTrue(Player.learnResearchFrom(teacher,
        "/guilds/monk/discipline/initiates-discipline.c"));
    int advancing = 1;
    while (advancing && Player.guildLevel("monk") < 5)
    {
        Player.addExperience(Player.experienceToNextLevel("monk"), "monk");
        advancing = Player.advanceLevel("monk");
    }
    ExpectEq(5, Player.guildLevel("monk"));
    ExpectTrue(Player.initiateResearch(
        "/guilds/monk/discipline/disciplined-breath.c"));
    ExpectFalse(Player.advanceRank("monk"));
    ExpectTrue(Player.learnResearchFrom(teacher, palm));
    for (int index = 0; index < 9; index++)
    {
        Player.stopFight(foe);
        foe.stopFight(Player);
        for (int tick = 0; tick < 4; tick++)
        {
            Player.heart_beat();
        }
        Player.hitPoints(10000);
        Player.staminaPoints(10000);
        ExpectTrue(foe.registerAttacker(Player));
        ExpectTrue(Player.registerAttacker(foe));
        ExpectTrue(Player.researchCommand("kata measured palm at opponent"));
    }
    ExpectEq(9, Player.countObservations(criteria));
    ExpectFalse(Player.canResearch(recovery));
    Player.save();
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    move_object(Player, room);
    ExpectEq(9, Player.countObservations(criteria));
    ExpectTrue(Player.isResearched(palm));
    ExpectFalse(Player.canResearch(recovery));
    Player.stopFight(foe);
    foe.stopFight(Player);
    for (int tick = 0; tick < 4; tick++)
    {
        Player.heart_beat();
    }
    Player.hitPoints(10000);
    Player.staminaPoints(10000);
    ExpectTrue(foe.registerAttacker(Player));
    ExpectTrue(Player.registerAttacker(foe));
    ExpectTrue(Player.researchCommand("kata measured palm at opponent"));
    ExpectEq(10, Player.countObservations(criteria));
    ExpectTrue(Player.canResearch(recovery));
    ExpectFalse(Player.initiateResearch(recovery));
    ExpectTrue(Player.learnResearchFrom(teacher, recovery));
    Player.save();
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    ExpectTrue(Player.isResearched(recovery));
    ExpectEq(10, Player.countObservations(criteria));
    destruct(foe);
    destruct(teacher);
    destruct(room);
}

/////////////////////////////////////////////////////////////////////////////
void PrepareRecognizedDisciple(object lian)
{
    ExpectTrue(Player.joinGuild("monk"));
    ExpectTrue(Player.learnResearchFrom(lian,
        "/guilds/monk/discipline/initiates-discipline.c"));
    int advancing = 1;
    while (advancing && Player.guildLevel("monk") < 10)
    {
        Player.addExperience(Player.experienceToNextLevel("monk"), "monk");
        advancing = Player.advanceLevel("monk");
    }
    ExpectEq(10, Player.guildLevel("monk"));
    ExpectTrue(Player.initiateResearch(
        "/guilds/monk/discipline/disciplined-breath.c"));
    ExpectTrue(Player.advanceRank("monk"));
    ExpectTrue(Player.learnResearchFrom(lian,
        "/guilds/monk/discipline/steady-practice.c"));
    ExpectTrue(Player.learnResearchFrom(lian,
        "/guilds/monk/discipline/teachers-recognition.c"));
    while (advancing && Player.guildLevel("monk") < 20)
    {
        Player.addExperience(Player.experienceToNextLevel("monk"), "monk");
        advancing = Player.advanceLevel("monk");
    }
    ExpectEq(20, Player.guildLevel("monk"));
    ExpectTrue(Player.initiateResearch(
        "/guilds/monk/discipline/students-awareness.c"));
    ExpectTrue(Player.advanceRank("monk"));
}

/////////////////////////////////////////////////////////////////////////////
void ExpandedKnowledgeAndSustainedFormSurviveRestore()
{
    string stance = "/guilds/monk/unarmed/crane-stance.c";
    object room = clone_object("/lib/environment/environment.c");
    object lian = clone_object("/guilds/monk/teachers/lian.c");
    object ren = clone_object("/guilds/monk/teachers/ren.c");
    move_object(Player, room);
    move_object(lian, room);
    move_object(ren, room);
    PrepareRecognizedDisciple(lian);
    Player.addResearchPoints(50);
    Player.addSkillPoints(200);
    ExpectTrue(Player.advanceSkill("dodge", 1));
    foreach(string item in ({ "measured-palm", "quiet-footwork",
        "hand-alignment", "driving-elbow", "elbow-anatomy", "crane-stance" }))
    {
        string path = "/guilds/monk/unarmed/" + item + ".c";
        ExpectTrue(Player.learnResearchFrom(
            lian.teachesResearch(path) ? lian : ren, path));
    }
    object elbow = load_object("/guilds/monk/unarmed/driving-elbow.c");
    int damage = elbow.getEffectsToApply(Player)["effects"]["damage hit points"];
    int maximum = Player.maxStaminaPoints();
    int dodge = Player.getSkill("dodge");
    ExpectTrue(Player.researchCommand("kata crane stance"));
    ExpectEq(dodge + 3, Player.getSkill("dodge"));
    ExpectEq(maximum - 8, Player.maxStaminaPoints());
    int points = Player.researchPoints();
    int respect = ren.relationshipValue(Player, "respect");
    Player.save();
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    move_object(Player, room);
    ExpectTrue(Player.isResearched(
        "/guilds/monk/unarmed/elbow-anatomy.c"));
    ExpectTrue(Player.sustainedResearchIsActive(stance));
    ExpectEq(damage,
        elbow.getEffectsToApply(Player)["effects"]["damage hit points"]);
    ExpectEq(maximum - 8, Player.maxStaminaPoints());
    ExpectEq(dodge + 3, Player.getSkill("dodge"));
    ExpectFalse(Player.learnResearchFrom(ren,
        "/guilds/monk/unarmed/elbow-anatomy.c"));
    ExpectEq(points, Player.researchPoints());
    ExpectEq(respect, ren.relationshipValue(Player, "respect"));
    ExpectTrue(Player.researchCommand("kata crane stance"));
    ExpectEq(maximum, Player.maxStaminaPoints());
    ExpectEq(dodge, Player.getSkill("dodge"));
    destruct(ren);
    destruct(lian);
    destruct(room);
}

/////////////////////////////////////////////////////////////////////////////
void EquippedKatanaAndItsSustainedGuardSurviveRestoreTogether()
{
    string stance = "/guilds/monk/katana/high-guard.c";
    object room = clone_object("/lib/environment/environment.c");
    object lian = clone_object("/guilds/monk/teachers/lian.c");
    object ren = clone_object("/guilds/monk/teachers/ren.c");
    move_object(Player, room);
    move_object(lian, room);
    move_object(ren, room);
    PrepareRecognizedDisciple(lian);
    Player.addResearchPoints(50);
    Player.addSkillPoints(200);
    ExpectTrue(Player.advanceSkill("parry", 1));
    foreach(string item in ({ "measured-cut", "grip-discipline",
        "guard-lines", "high-guard" }))
    {
        string path = "/guilds/monk/katana/" + item + ".c";
        ExpectTrue(Player.learnResearchFrom(
            lian.teachesResearch(path) ? lian : ren, path));
    }
    object armor = clone_object("/lib/items/armor.c");
    armor.set("blueprint", "plate armor");
    armor.set("name", "training armor");
    move_object(armor, Player);
    ExpectTrue(armor.equip("training armor"));
    object katana = clone_object("/lib/items/weapon.c");
    katana.set("blueprint", "katana");
    katana.set("name", "training katana");
    move_object(katana, Player);
    ExpectTrue(katana.equip("training katana"));
    int maximum = Player.maxStaminaPoints();
    int parry = Player.getSkill("parry");
    ExpectTrue(Player.researchCommand("kata high guard"));
    ExpectEq(parry + 3, Player.getSkill("parry"));
    Player.save();
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    move_object(Player, room);
    object equipped = Player.equipmentInSlot("wielded primary");
    ExpectTrue(objectp(equipped));
    if (equipped)
    {
        ExpectEq("katana", equipped.query("blueprint"));
    }
    ExpectTrue(Player.sustainedResearchIsActive(stance));
    ExpectEq(maximum - 8, Player.maxStaminaPoints());
    ExpectEq(parry + 3, Player.getSkill("parry"));
    ExpectTrue(Player.researchCommand("kata high guard"));
    ExpectEq(maximum, Player.maxStaminaPoints());
    ExpectEq(parry, Player.getSkill("parry"));
    destruct(ren);
    destruct(lian);
    destruct(room);
}

/////////////////////////////////////////////////////////////////////////////
varargs void RoundTripBladeStudy(string discipline, string *lessons,
    string blueprint, string offhand, int reservation, string strike,
    string bonusSkill)
{
    if (!bonusSkill)
    {
        bonusSkill = "parry";
    }
    string base = "/guilds/monk/" + discipline + "/";
    string stance = base + lessons[<1] + ".c";
    string knowledge = base + lessons[<2] + ".c";
    object room = clone_object("/lib/environment/environment.c");
    object lian = clone_object("/guilds/monk/teachers/lian.c");
    object sora = clone_object("/guilds/monk/teachers/sora.c");
    move_object(Player, room);
    move_object(lian, room);
    move_object(sora, room);
    PrepareRecognizedDisciple(lian);
    Player.addResearchPoints(50);
    Player.addSkillPoints(200);
    ExpectTrue(Player.advanceSkill(bonusSkill, 1));
    foreach(string item in lessons)
    {
        TeachMonkTrialLesson(Player, ({ lian, sora }), base + item + ".c");
    }
    object weapon = clone_object("/lib/items/weapon.c");
    weapon.set("blueprint", blueprint);
    weapon.set("name", "practice sword");
    move_object(weapon, Player);
    ExpectTrue(weapon.equip("practice sword"));
    int twoHanded = weapon.query("equipment locations") == TwohandedWeapon;
    if (offhand)
    {
        object companion = clone_object("/lib/items/weapon.c");
        companion.set("blueprint", offhand);
        companion.set("name", "companion blade");
        move_object(companion, Player);
        ExpectTrue(companion.equip("companion blade offhand"));
    }
    object guard = load_object(stance);
    object cut = load_object(base + strike + ".c");
    string command = guard.query("command template");
    int maximum = Player.maxStaminaPoints();
    int skill = Player.getSkill(bonusSkill);
    ExpectTrue(Player.researchCommand(command));
    ExpectEq(skill + 3, Player.getSkill(bonusSkill));
    int damage = cut.getEffectsToApply(Player)["effects"]["damage hit points"];
    int points = Player.researchPoints();
    int respect = sora.relationshipValue(Player, "respect");
    Player.save();
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    move_object(Player, room);
    object primary = Player.equipmentInSlot("wielded primary");
    object companion = Player.equipmentInSlot("wielded offhand");
    ExpectTrue(objectp(primary));
    if (offhand || twoHanded)
    {
        ExpectTrue(objectp(companion));
        if (companion)
        {
            ExpectEq(offhand ? offhand : blueprint,
                companion.query("blueprint"));
            ExpectEq(twoHanded, primary == companion);
        }
    }
    else
    {
        ExpectFalse(objectp(companion));
    }
    if (primary)
    {
        ExpectEq(blueprint, primary.query("blueprint"));
    }
    ExpectTrue(Player.isResearched(knowledge));
    ExpectTrue(Player.sustainedResearchIsActive(stance));
    ExpectEq(maximum - reservation, Player.maxStaminaPoints());
    ExpectEq(skill + 3, Player.getSkill(bonusSkill));
    ExpectEq(damage,
        cut.getEffectsToApply(Player)["effects"]["damage hit points"]);
    ExpectFalse(Player.learnResearchFrom(sora, knowledge));
    ExpectEq(points, Player.researchPoints());
    ExpectEq(respect, sora.relationshipValue(Player, "respect"));
    ExpectTrue(Player.researchCommand(command));
    ExpectEq(maximum, Player.maxStaminaPoints());
    ExpectEq(skill, Player.getSkill(bonusSkill));
    destruct(sora);
    destruct(lian);
    destruct(room);
}

/////////////////////////////////////////////////////////////////////////////
void PairedWeaponsKnowledgeAndActiveGuardSurviveRestoreTogether()
{
    RoundTripBladeStudy("paired-swords", ({ "paired-grip", "companion-grip",
        "paired-guard", "linked-cut", "linked-lines", "paired-high-guard" }),
        "katana", "wakisashi", 10, "linked-cut");
}

/////////////////////////////////////////////////////////////////////////////
void OdachiKnowledgeAndActiveGuardSurviveRestoreTogether()
{
    RoundTripBladeStudy("odachi", ({ "longblade-grip", "longblade-footing",
        "longblade-guard", "committed-cut", "commitment-theory",
        "horizon-guard" }), "odachi", 0, 12, "committed-cut");
}

/////////////////////////////////////////////////////////////////////////////
void KamaKnowledgeAndActiveWardSurviveRestoreTogether()
{
    RoundTripBladeStudy("kama", ({ "hooked-grip", "sickle-footing",
        "sickle-guard", "measured-hook", "hook-geometry", "sickle-ward" }),
        "kama", 0, 10, "measured-hook");
}

/////////////////////////////////////////////////////////////////////////////
void ClawKnowledgeAndActiveShelterSurviveRestoreTogether()
{
    RoundTripBladeStudy("claw", ({ "claw-grip", "claw-footwork",
        "measured-rake", "rake-geometry", "claw-shelter" }),
        "tiger claws", 0, 8, "measured-rake", "dodge");
}

/////////////////////////////////////////////////////////////////////////////
void BowArrowsKnowledgePracticeAndActiveDrawSurviveRestoreTogether()
{
    string base = "/guilds/monk/archery/";
    string draw = base + "measured-draw.c";
    string form = base + "patient-draw.c";
    object room = clone_object("/lib/environment/environment.c");
    object lian = clone_object("/guilds/monk/teachers/lian.c");
    object iori = clone_object("/guilds/monk/teachers/iori.c");
    object foe = clone_object("/lib/realizations/npc.c");
    foe.Name("opponent");
    foe.effectiveLevel(10);
    foe.setMaxHitPoints(10000);
    move_object(Player, room);
    move_object(lian, room);
    move_object(iori, room);
    move_object(foe, room);
    PrepareRecognizedDisciple(lian);
    Player.addResearchPoints(50);
    Player.addSkillPoints(200);
    ExpectTrue(Player.advanceSkill("bow", 1));
    foreach(string item in ({ "measured-draw", "archers-grip",
        "draw-geometry", "archers-footing", "archers-guard", "patient-draw" }))
    {
        ExpectTrue(Player.learnResearchFrom(iori, base + item + ".c"));
    }
    object bow = clone_object("/lib/items/weapon.c");
    bow.set("blueprint", "long bow");
    bow.set("name", "practice bow");
    move_object(bow, Player);
    ExpectTrue(bow.equip("practice bow"));
    object arrows = clone_object("/lib/items/ammunition.c");
    arrows.set("name", "practice quiver");
    arrows.set("ammunition type", "arrow");
    arrows.set("max capacity", 24);
    arrows.set("quantity", 2);
    move_object(arrows, Player);
    Player.staminaPoints(10000);
    ExpectTrue(foe.registerAttacker(Player));
    ExpectTrue(Player.registerAttacker(foe));
    ExpectTrue(Player.researchCommand("kata measured draw at opponent"));
    ExpectEq(1, arrows.query("quantity"));
    Player.stopFight(foe);
    foe.stopFight(Player);
    for (int tick = 0; tick < 7; tick++)
    {
        Player.heart_beat();
    }
    int skill = Player.getSkill("bow");
    int maximum = Player.maxStaminaPoints();
    ExpectTrue(Player.researchCommand("kata patient draw"));
    ExpectEq(skill + 3, Player.getSkill("bow"));
    object shot = load_object(draw);
    int damage = shot.getEffectsToApply(Player)["effects"]["damage hit points"];
    int points = Player.researchPoints();
    int respect = iori.relationshipValue(Player, "respect");
    Player.save();
    destruct(arrows);
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    move_object(Player, room);
    object primary = Player.equipmentInSlot("wielded primary");
    ExpectTrue(objectp(primary));
    ExpectEq(primary, Player.equipmentInSlot("wielded offhand"));
    if (primary)
    {
        ExpectEq("long bow", primary.query("blueprint"));
    }
    arrows = present("practice quiver", Player);
    ExpectTrue(objectp(arrows));
    if (arrows)
    {
        ExpectEq(1, arrows.query("quantity"));
    }
    ExpectTrue(Player.isResearched(base + "draw-geometry.c"));
    ExpectTrue(Player.isResearched(base + "root.c"));
    ExpectTrue(Player.sustainedResearchIsActive(form));
    ExpectEq(maximum - 10, Player.maxStaminaPoints());
    ExpectEq(skill + 3, Player.getSkill("bow"));
    ExpectEq(damage,
        shot.getEffectsToApply(Player)["effects"]["damage hit points"]);
    ExpectEq(1, Player.countObservations(([
        "type":"combat.kata", "research":draw, "qualifying opponent":1
    ])));
    ExpectFalse(Player.learnResearchFrom(iori, base + "draw-geometry.c"));
    ExpectEq(points, Player.researchPoints());
    ExpectEq(respect, iori.relationshipValue(Player, "respect"));
    ExpectTrue(Player.researchCommand("kata patient draw"));
    ExpectEq(skill, Player.getSkill("bow"));
    ExpectEq(maximum, Player.maxStaminaPoints());
    Player.staminaPoints(10000);
    ExpectTrue(Player.researchCommand("kata measured draw at opponent"));
    if (arrows)
    {
        ExpectEq(0, arrows.query("quantity"));
    }
    Player.stopFight(foe);
    foe.stopFight(Player);
    for (int tick = 0; tick < 7; tick++)
    {
        Player.heart_beat();
    }
    Player.save();
    if (objectp(arrows))
    {
        destruct(arrows);
    }
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    move_object(Player, room);
    arrows = present("practice quiver", Player);
    ExpectTrue(objectp(arrows));
    if (arrows)
    {
        ExpectEq(0, arrows.query("quantity"));
    }
    ExpectFalse(Player.sustainedResearchIsActive(form));
    ExpectEq(maximum, Player.maxStaminaPoints());
    ExpectFalse(Player.researchCommand("kata measured draw at opponent"));
    ExpectEq(2, Player.countObservations(([
        "type":"combat.kata", "research":draw
    ])));
    destruct(foe);
    destruct(iori);
    destruct(lian);
    destruct(room);
}

/////////////////////////////////////////////////////////////////////////////
void AdeptTrialPracticeCertificationAndPromotionSurviveRestore()
{
    string trial = "/guilds/monk/discipline/adepts-trial.c";
    string palm = "/guilds/monk/unarmed/measured-palm.c";
    mapping criteria = ([
        "type":"combat.kata",
        "research":palm,
        "qualifying opponent":1
    ]);
    object room = clone_object("/lib/environment/environment.c");
    object lian = clone_object("/guilds/monk/teachers/lian.c");
    object ren = clone_object("/guilds/monk/teachers/ren.c");
    object foe = clone_object("/lib/realizations/npc.c");
    foe.Name("opponent");
    foe.effectiveLevel(15);
    foe.setMaxHitPoints(10000);
    move_object(Player, room);
    move_object(lian, room);
    move_object(ren, room);
    move_object(foe, room);
    PrepareRecognizedDisciple(lian);
    int advancing = 1;
    while (advancing && Player.guildLevel("monk") < 30)
    {
        Player.addExperience(Player.experienceToNextLevel("monk"), "monk");
        advancing = Player.advanceLevel("monk");
    }
    ExpectEq(30, Player.guildLevel("monk"));
    ExpectTrue(Player.initiateResearch(
        "/guilds/monk/discipline/disciples-insight.c"));
    ExpectTrue(Player.learnResearchFrom(lian, palm));
    for (int index = 0; index < 9; index++)
    {
        Player.stopFight(foe);
        foe.stopFight(Player);
        for (int tick = 0; tick < 4; tick++)
        {
            Player.heart_beat();
        }
        Player.hitPoints(10000);
        Player.staminaPoints(10000);
        ExpectTrue(foe.registerAttacker(Player));
        ExpectTrue(Player.registerAttacker(foe));
        ExpectTrue(Player.researchCommand("kata measured palm at opponent"));
    }
    ExpectEq(9, Player.countObservations(criteria));
    ExpectFalse(Player.canResearch(trial));
    ExpectFalse(Player.advanceRank("monk"));
    Player.save();
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    move_object(Player, room);
    ExpectEq("disciple", Player.guildRank("monk"));
    ExpectEq(9, Player.countObservations(criteria));
    ExpectFalse(Player.canResearch(trial));
    ExpectFalse(Player.advanceRank("monk"));
    Player.stopFight(foe);
    foe.stopFight(Player);
    for (int tick = 0; tick < 4; tick++)
    {
        Player.heart_beat();
    }
    Player.hitPoints(10000);
    Player.staminaPoints(10000);
    ExpectTrue(foe.registerAttacker(Player));
    ExpectTrue(Player.registerAttacker(foe));
    ExpectTrue(Player.researchCommand("kata measured palm at opponent"));
    ExpectEq(10, Player.countObservations(criteria));
    ExpectTrue(Player.canResearch(trial));
    ExpectFalse(Player.advanceRank("monk"));
    int points = Player.researchPoints();
    ExpectTrue(Player.learnResearchFrom(ren, trial));
    ExpectEq("disciple", Player.guildRank("monk"));
    ExpectEq(points, Player.researchPoints());
    Player.save();
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    move_object(Player, room);
    ExpectEq("disciple", Player.guildRank("monk"));
    ExpectTrue(Player.isResearched(trial));
    ExpectEq(points, Player.researchPoints());
    ExpectEq(2, ren.relationshipValue(Player, "respect"));
    ExpectFalse(Player.learnResearchFrom(ren, trial));
    ExpectTrue(Player.advanceRank("monk"));
    ExpectEq("adept", Player.guildRank("monk"));
    Player.save();
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    move_object(Player, room);
    ExpectEq("adept", Player.guildRank("monk"));
    ExpectTrue(Player.isResearched(trial));
    ExpectEq(points, Player.researchPoints());
    ExpectEq(10, Player.countObservations(criteria));
    ExpectEq(2, ren.relationshipValue(Player, "respect"));
    ExpectEq(1, Player.countObservations(([
        "type":"training.completed",
        "research":trial
    ])));
    ExpectFalse(Player.learnResearchFrom(ren, trial));
    ExpectTrue(Player.demoteRank("monk"));
    ExpectTrue(Player.advanceRank("monk"));
    ExpectEq("adept", Player.guildRank("monk"));
    ExpectEq(points, Player.researchPoints());
    ExpectEq(2, ren.relationshipValue(Player, "respect"));
    destruct(foe);
    destruct(ren);
    destruct(lian);
    destruct(room);
}

/////////////////////////////////////////////////////////////////////////////
void ExistingAdeptsRestoreWithoutRetroactiveTrialOrDemotion()
{
    object room = clone_object("/lib/environment/environment.c");
    object lian = clone_object("/guilds/monk/teachers/lian.c");
    move_object(Player, room);
    move_object(lian, room);
    PrepareRecognizedDisciple(lian);
    int advancing = 1;
    while (advancing && Player.guildLevel("monk") < 30)
    {
        Player.addExperience(Player.experienceToNextLevel("monk"), "monk");
        advancing = Player.advanceLevel("monk");
    }
    ExpectTrue(Player.initiateResearch(
        "/guilds/monk/discipline/disciples-insight.c"));
    Player.save();
    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    mapping legacy = dataAccess.getPlayerData("gorthaur");
    legacy["guilds"]["monk"]["rank"] = "adept";
    dataAccess.savePlayerData(legacy);
    destruct(dataAccess);
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    ExpectEq("adept", Player.guildRank("monk"));
    ExpectFalse(Player.isResearched(
        "/guilds/monk/discipline/adepts-trial.c"));
    while (advancing && Player.guildLevel("monk") < 40)
    {
        Player.addExperience(Player.experienceToNextLevel("monk"), "monk");
        advancing = Player.advanceLevel("monk");
    }
    ExpectEq(40, Player.guildLevel("monk"));
    ExpectTrue(Player.initiateResearch(
        "/guilds/monk/discipline/adepts-focus.c"));
    ExpectFalse(Player.advanceRank("monk"));
    object ren = clone_object("/guilds/monk/teachers/ren.c");
    move_object(Player, room);
    move_object(ren, room);
    CompleteMonkUpperTrial(Player, lian, ren, 0);
    ExpectTrue(Player.advanceRank("monk"));
    ExpectEq("senior disciple", Player.guildRank("monk"));
    ExpectFalse(Player.isResearched(
        "/guilds/monk/discipline/adepts-trial.c"));
    destruct(ren);
    destruct(lian);
    destruct(room);
}

/////////////////////////////////////////////////////////////////////////////
void UpperTrialThresholdsCertificationsAndPromotionsSurviveRestore()
{
    object room = clone_object("/lib/environment/environment.c");
    object lian = clone_object("/guilds/monk/teachers/lian.c");
    object ren = clone_object("/guilds/monk/teachers/ren.c");
    move_object(Player, room);
    move_object(lian, room);
    move_object(ren, room);
    PrepareRecognizedDisciple(lian);
    Player.addResearchPoints(100);
    int advancing = 1;
    while (advancing && Player.guildLevel("monk") < 30)
    {
        Player.addExperience(Player.experienceToNextLevel("monk"), "monk");
        advancing = Player.advanceLevel("monk");
    }
    ExpectTrue(Player.initiateResearch(
        "/guilds/monk/discipline/disciples-insight.c"));
    for (int use = 0; use < 10; use++)
    {
        ExpectTrue(mappingp(Player.recordObservation(([
            "type":"combat.kata",
            "context":([
                "research":"/guilds/monk/unarmed/measured-palm.c",
                "qualifying opponent":1
            ])
        ]), 1)));
    }
    ExpectTrue(Player.learnResearchFrom(ren,
        "/guilds/monk/discipline/adepts-trial.c"));
    ExpectTrue(Player.advanceRank("monk"));
    string *trials = ({ "senior-disciples-trial", "master-candidates-trial",
        "masters-trial" });
    string *foundations = ({ "adepts-focus", "inner-discipline",
        "mastery-of-fundamentals" });
    string *ranks = ({ "adept", "senior disciple", "master candidate",
        "master" });
    for (int stage = 0; stage < sizeof(trials); stage++)
    {
        while (advancing && Player.guildLevel("monk") <
            MonkPromotionLevels[stage + 3])
        {
            Player.addExperience(Player.experienceToNextLevel("monk"), "monk");
            advancing = Player.advanceLevel("monk");
        }
        ExpectEq(MonkPromotionLevels[stage + 3], Player.guildLevel("monk"));
        ExpectTrue(Player.initiateResearch("/guilds/monk/discipline/" +
            foundations[stage] + ".c"));
        string path = "/guilds/monk/discipline/" + trials[stage] + ".c";
        object trial = getService("research")->researchObject(path);
        mapping route = trial.getPrerequisites()["specialist mastery"]
            ["prerequisites"][0];
        foreach(string lesson, mapping condition in route)
        {
            if (condition["type"] == "research")
            {
                TeachMonkTrialLesson(Player, ({ lian, ren }), lesson);
            }
        }
        mapping practice = route["qualifying practice"];
        mapping observation = ([
            "type":practice["criteria"]["type"],
            "context":([
                "research":practice["criteria"]["research"],
                "qualifying opponent":1
            ])
        ]);
        for (int use = 0; use < practice["value"] - 1; use++)
        {
            ExpectTrue(mappingp(Player.recordObservation(
                deep_copy(observation), 1)));
        }
        int points = Player.researchPoints();
        int respect = ren.relationshipValue(Player, "respect");
        Player.save();
        destruct(Player);
        Player = clone_object("/lib/realizations/player.c");
        Player.restore("gorthaur");
        move_object(Player, room);
        ExpectEq(ranks[stage], Player.guildRank("monk"));
        ExpectEq(points, Player.researchPoints());
        foreach(string lesson, mapping condition in route)
        {
            if (condition["type"] == "research")
            {
                ExpectTrue(Player.isResearched(lesson));
            }
        }
        ExpectEq(practice["value"] - 1,
            Player.countObservations(practice["criteria"]));
        ExpectFalse(Player.canResearch(path));
        ExpectFalse(Player.advanceRank("monk"));
        ExpectTrue(mappingp(Player.recordObservation(
            deep_copy(observation), 1)), "Final practice: " + path);
        ExpectEq(practice["value"],
            Player.countObservations(practice["criteria"]));
        ExpectTrue(Player.canResearch(path), "Eligibility: " + path);
        ExpectTrue(Player.learnResearchFrom(ren, path));
        ExpectEq(points, Player.researchPoints());
        ExpectEq(respect + 2, ren.relationshipValue(Player, "respect"));
        ExpectEq(ranks[stage], Player.guildRank("monk"));
        Player.save();
        destruct(Player);
        Player = clone_object("/lib/realizations/player.c");
        Player.restore("gorthaur");
        move_object(Player, room);
        ExpectTrue(Player.isResearched(path));
        ExpectEq(points, Player.researchPoints());
        ExpectEq(respect + 2, ren.relationshipValue(Player, "respect"));
        ExpectFalse(Player.learnResearchFrom(ren, path));
        ExpectTrue(Player.advanceRank("monk"));
        Player.save();
        destruct(Player);
        Player = clone_object("/lib/realizations/player.c");
        Player.restore("gorthaur");
        move_object(Player, room);
        ExpectEq(ranks[stage + 1], Player.guildRank("monk"));
        ExpectTrue(Player.isResearched(path));
        ExpectEq(points, Player.researchPoints());
        ExpectEq(respect + 2, ren.relationshipValue(Player, "respect"));
        ExpectEq(1, Player.countObservations(([
            "type":"training.completed",
            "research":path
        ])));
    }
    destruct(ren);
    destruct(lian);
    destruct(room);
}

/////////////////////////////////////////////////////////////////////////////
void ExistingUpperRanksRestoreWithoutRetroactiveCertifications()
{
    ExpectTrue(Player.joinGuild("monk"));
    int advancing = 1;
    while (advancing && Player.guildLevel("monk") < 30)
    {
        Player.addExperience(Player.experienceToNextLevel("monk"), "monk");
        advancing = Player.advanceLevel("monk");
    }
    Player.save();
    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    mapping legacy = dataAccess.getPlayerData("gorthaur");
    foreach(string rank in ({ "senior disciple", "master candidate", "master" }))
    {
        destruct(Player);
        legacy["guilds"]["monk"]["rank"] = rank;
        dataAccess.savePlayerData(legacy);
        Player = clone_object("/lib/realizations/player.c");
        Player.restore("gorthaur");
        ExpectEq(rank, Player.guildRank("monk"));
        ExpectEq(30, Player.guildLevel("monk"));
        foreach(string trial in ({ "senior-disciples-trial",
            "master-candidates-trial", "masters-trial" }))
        {
            ExpectFalse(Player.isResearched("/guilds/monk/discipline/" +
                trial + ".c"));
        }
    }
    destruct(dataAccess);
}

/////////////////////////////////////////////////////////////////////////////
void BludgeonLessonsAndPracticeSurviveRestoreAcrossWeaponFamilies()
{
    string impact = "/guilds/monk/bludgeon/measured-impact.c";
    string guard = "/guilds/monk/bludgeon/settled-guard.c";
    mapping criteria = ([
        "type":"combat.kata", "research":impact, "qualifying opponent":1
    ]);
    object room = clone_object("/lib/environment/environment.c");
    object lian = clone_object("/guilds/monk/teachers/lian.c");
    object ren = clone_object("/guilds/monk/teachers/ren.c");
    object foe = clone_object("/lib/realizations/npc.c");
    foe.Name("opponent");
    foe.effectiveLevel(10);
    foe.setMaxHitPoints(10000);
    object mace = clone_object("/lib/items/weapon.c");
    mace.set("blueprint", "mace");
    mace.set("name", "mace");
    object staff = clone_object("/lib/items/weapon.c");
    staff.set("blueprint", "staff");
    staff.set("name", "staff");
    object other = clone_object("/lib/items/weapon.c");
    other.set("blueprint", "katana");
    other.set("name", "other");
    move_object(Player, room);
    move_object(lian, room);
    move_object(ren, room);
    move_object(foe, room);
    move_object(mace, Player);
    PrepareRecognizedDisciple(lian);
    int parry = Player.researchBonusTo("parry");
    ExpectTrue(Player.learnResearchFrom(ren, impact));
    ExpectTrue(Player.learnResearchFrom(ren, guard));
    ExpectTrue(mace.equip("mace"));
    ExpectEq(parry + 1, Player.researchBonusTo("parry"));
    Player.staminaPoints(10000);
    ExpectTrue(foe.registerAttacker(Player));
    ExpectTrue(Player.registerAttacker(foe));
    ExpectTrue(Player.researchCommand("kata measured impact at opponent"));
    ExpectEq(1, Player.countObservations(criteria));
    Player.stopFight(foe);
    foe.stopFight(Player);
    for (int tick = 0; tick < 4; tick++)
    {
        Player.heart_beat();
    }
    ExpectTrue(mace.unequip("mace"));
    move_object(mace, room);
    int points = Player.researchPoints();
    Player.save();
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    move_object(Player, room);
    move_object(staff, Player);
    move_object(other, Player);
    ExpectTrue(Player.isResearched(impact));
    ExpectTrue(Player.isResearched(guard));
    ExpectTrue(Player.isResearched("/guilds/monk/bludgeon/root.c"));
    ExpectTrue(member(Player.availableResearchTrees(),
        "/guilds/monk/bludgeon.c") >= 0);
    ExpectEq(points, Player.researchPoints());
    ExpectEq(1, Player.countObservations(criteria));
    ExpectEq(parry, Player.researchBonusTo("parry"));
    ExpectEq(4, ren.relationshipValue(Player, "respect"));
    ExpectFalse(Player.learnResearchFrom(ren, impact));
    ExpectFalse(Player.learnResearchFrom(ren, guard));
    ExpectEq(points, Player.researchPoints());
    ExpectTrue(other.equip("other"));
    ExpectFalse(Player.researchCommand("kata measured impact at opponent"));
    ExpectEq(parry, Player.researchBonusTo("parry"));
    ExpectTrue(other.unequip("other"));
    ExpectTrue(staff.equip("staff"));
    ExpectEq(parry + 1, Player.researchBonusTo("parry"));
    Player.staminaPoints(10000);
    ExpectTrue(foe.registerAttacker(Player));
    ExpectTrue(Player.registerAttacker(foe));
    ExpectTrue(Player.researchCommand("kata measured impact at opponent"));
    ExpectEq(2, Player.countObservations(criteria));
    ExpectEq(1, Player.countObservations(([
        "type":"combat.kata", "research":impact, "weapon":"staff"
    ])));
    destruct(other);
    destruct(staff);
    destruct(mace);
    destruct(foe);
    destruct(ren);
    destruct(lian);
    destruct(room);
}

/////////////////////////////////////////////////////////////////////////////
void ChiAndActiveWardSurviveRestoreWithoutDuplicatedReservations()
{
    string pulse = "/guilds/monk/pure-chi/focused-pulse.c";
    string ward = "/guilds/monk/mana-shield/mindful-ward.c";
    object room = clone_object("/lib/environment/environment.c");
    object lian = clone_object("/guilds/monk/teachers/lian.c");
    object ren = clone_object("/guilds/monk/teachers/ren.c");
    object foe = clone_object("/lib/realizations/npc.c");
    foe.Name("opponent");
    foe.effectiveLevel(10);
    foe.setMaxHitPoints(10000);
    move_object(Player, room);
    move_object(lian, room);
    move_object(ren, room);
    move_object(foe, room);
    PrepareRecognizedDisciple(lian);
    ExpectTrue(Player.learnResearchFrom(ren, pulse));
    ExpectTrue(Player.learnResearchFrom(ren, ward));
    Player.hitPoints(10000);
    Player.spellPoints(10000);
    int damage = Player.hit(20, "physical", foe);
    ExpectTrue(damage > 0);
    Player.hitPoints(10000);
    ExpectTrue(Player.researchCommand("chi focused pulse at opponent"));
    Player.stopFight(foe);
    foe.stopFight(Player);
    for (int tick = 0; tick < 4; tick++)
    {
        Player.heart_beat();
    }
    int maximum = Player.maxStaminaPoints();
    ExpectTrue(Player.researchCommand("mana shield"));
    ExpectTrue(Player.hasTraitOfRoot("mana shield"));
    ExpectEq(maximum - 10, Player.maxStaminaPoints());
    Player.spellPoints(-Player.spellPoints());
    Player.spellPoints(37);
    ExpectEq(37, Player.spellPoints());
    int points = Player.researchPoints();
    Player.save();
    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    mapping snapshot = dataAccess.getPlayerData("gorthaur");
    ExpectEq("/guilds/monk/mana-shield/ward-trait.c",
        snapshot["temporaryTraits"]);
    destruct(dataAccess);
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    move_object(Player, room);
    ExpectTrue(Player.isResearched(pulse));
    ExpectTrue(Player.isResearched(ward));
    ExpectTrue(Player.isResearched("/guilds/monk/pure-chi/root.c"));
    ExpectTrue(Player.isResearched("/guilds/monk/mana-shield/root.c"));
    ExpectTrue(Player.sustainedResearchIsActive(ward));
    ExpectTrue(Player.hasTraitOfRoot("mana shield"));
    ExpectEq(maximum - 10, Player.maxStaminaPoints());
    ExpectEq(37, Player.spellPoints());
    ExpectEq(points, Player.researchPoints());
    ExpectEq(4, ren.relationshipValue(Player, "respect"));
    ExpectEq(1, Player.countObservations(([
        "type":"research.use", "research":pulse
    ])));
    ExpectEq(1, Player.countObservations(([
        "type":"research.use", "subject":ward
    ])));
    ExpectFalse(Player.learnResearchFrom(ren, pulse));
    ExpectFalse(Player.learnResearchFrom(ren, ward));
    ExpectEq(points, Player.researchPoints());
    int health = Player.hitPoints();
    ExpectEq(0, Player.hit(20, "physical", foe));
    ExpectEq(health, Player.hitPoints());
    ExpectEq(37 - damage, Player.spellPoints());
    ExpectTrue(Player.researchCommand("mana shield"));
    ExpectFalse(Player.hasTraitOfRoot("mana shield"));
    ExpectEq(maximum, Player.maxStaminaPoints());
    ExpectEq(37 - damage, Player.spellPoints());
    Player.save();
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    ExpectTrue(Player.isResearched(ward));
    ExpectFalse(Player.sustainedResearchIsActive(ward));
    ExpectFalse(Player.hasTraitOfRoot("mana shield"));
    ExpectEq(maximum, Player.maxStaminaPoints());
    ExpectEq(37 - damage, Player.spellPoints());
    ExpectEq(1, Player.countObservations(([
        "type":"research.use", "subject":ward
    ])));
    ExpectEq(1, Player.countObservations(([
        "type":"research.deactivated", "subject":ward
    ])));
    destruct(foe);
    destruct(ren);
    destruct(lian);
    destruct(room);
}

/////////////////////////////////////////////////////////////////////////////
void KatanaKnowledgePracticeAndConditionalBonusSurviveRestore()
{
    string cut = "/guilds/monk/katana/measured-cut.c";
    string edge = "/guilds/monk/katana/settled-edge.c";
    mapping criteria = ([
        "type":"combat.kata", "research":cut, "weapon":"katana"
    ]);
    object room = clone_object("/lib/environment/environment.c");
    object teacher = clone_object("/guilds/monk/teachers/lian.c");
    object foe = clone_object("/lib/realizations/npc.c");
    foe.Name("opponent");
    foe.effectiveLevel(5);
    foe.setMaxHitPoints(10000);
    object katana = clone_object("/lib/items/weapon.c");
    katana.set("blueprint", "katana");
    katana.set("name", "katana");
    object other = clone_object("/lib/items/weapon.c");
    other.set("blueprint", "bastard sword");
    other.set("name", "other");
    move_object(Player, room);
    move_object(teacher, room);
    move_object(foe, room);
    move_object(katana, Player);
    ExpectTrue(Player.joinGuild("monk"));
    ExpectTrue(Player.learnResearchFrom(teacher,
        "/guilds/monk/discipline/initiates-discipline.c"));
    int advancing = 1;
    while (advancing && Player.guildLevel("monk") < 10)
    {
        Player.addExperience(Player.experienceToNextLevel("monk"), "monk");
        advancing = Player.advanceLevel("monk");
    }
    ExpectEq(10, Player.guildLevel("monk"));
    ExpectTrue(Player.initiateResearch(
        "/guilds/monk/discipline/disciplined-breath.c"));
    ExpectTrue(Player.advanceRank("monk"));
    ExpectTrue(Player.learnResearchFrom(teacher, cut));
    ExpectTrue(Player.learnResearchFrom(teacher, edge));
    ExpectTrue(katana.equip("katana"));
    ExpectEq(1, Player.researchBonusTo("hand and a half sword"));
    Player.staminaPoints(10000);
    ExpectTrue(foe.registerAttacker(Player));
    ExpectTrue(Player.registerAttacker(foe));
    ExpectTrue(Player.researchCommand("kata measured cut at opponent"));
    ExpectEq(1, Player.countObservations(criteria));
    Player.stopFight(foe);
    foe.stopFight(Player);
    for (int tick = 0; tick < 4; tick++)
    {
        Player.heart_beat();
    }
    ExpectTrue(katana.unequip("katana"));
    move_object(katana, room);
    int points = Player.researchPoints();
    Player.save();
    destruct(Player);
    Player = clone_object("/lib/realizations/player.c");
    Player.restore("gorthaur");
    move_object(Player, room);
    move_object(katana, Player);
    move_object(other, Player);
    ExpectTrue(Player.isResearched(cut));
    ExpectTrue(Player.isResearched(edge));
    ExpectTrue(Player.isResearched("/guilds/monk/katana/root.c"));
    ExpectTrue(member(Player.availableResearchTrees(),
        "/guilds/monk/katana.c") >= 0);
    ExpectEq(1, Player.countObservations(criteria));
    ExpectEq(points, Player.researchPoints());
    ExpectEq(0, Player.researchBonusTo("hand and a half sword"));
    ExpectFalse(Player.learnResearchFrom(teacher, cut));
    ExpectFalse(Player.learnResearchFrom(teacher, edge));
    ExpectEq(points, Player.researchPoints());
    ExpectTrue(other.equip("other"));
    ExpectFalse(Player.researchCommand("kata measured cut at opponent"));
    ExpectEq(0, Player.researchBonusTo("hand and a half sword"));
    ExpectTrue(other.unequip("other"));
    ExpectTrue(katana.equip("katana"));
    ExpectEq(1, Player.researchBonusTo("hand and a half sword"));
    Player.staminaPoints(10000);
    ExpectTrue(foe.registerAttacker(Player));
    ExpectTrue(Player.registerAttacker(foe));
    ExpectTrue(Player.researchCommand("kata measured cut at opponent"));
    ExpectEq(2, Player.countObservations(criteria));
    destruct(other);
    destruct(katana);
    destruct(foe);
    destruct(teacher);
    destruct(room);
}
