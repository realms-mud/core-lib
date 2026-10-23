//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object User;
object Lian;
object Ren;
object Target;
object Room;
object Weapon;
object Other;
object Offhand;
string Impact = "/guilds/monk/bludgeon/measured-impact.c";
string Guard = "/guilds/monk/bludgeon/settled-guard.c";
string KataCommand = "kata measured impact at opponent";

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    load_object("/guilds/monk/monk.c");
    ignoreList += ({ "AdvanceMonkToLevel", "PrepareDisciple", "ReadyKata" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Room = clone_object("/lib/environment/environment.c");
    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name("disciple");
    User.Str(20);
    User.Int(20);
    User.Dex(20);
    User.Con(20);
    User.Wis(20);
    User.Chr(20);
    User.Race("human");
    User.colorConfiguration("none");
    Lian = clone_object("/guilds/monk/teachers/lian.c");
    Ren = clone_object("/guilds/monk/teachers/ren.c");
    Target = clone_object("/lib/realizations/npc.c");
    Target.Name("opponent");
    Target.Race("human");
    Target.effectiveLevel(6);
    Target.setMaxHitPoints(10000);
    Weapon = clone_object("/lib/items/weapon.c");
    Weapon.set("blueprint", "mace");
    Weapon.set("name", "implement");
    Other = clone_object("/lib/items/weapon.c");
    Other.set("blueprint", "katana");
    Other.set("name", "other");
    Offhand = clone_object("/lib/items/weapon.c");
    Offhand.set("blueprint", "dagger");
    Offhand.set("name", "dagger");
    move_object(User, Room);
    move_object(Lian, Room);
    move_object(Ren, Room);
    move_object(Target, Room);
    move_object(Weapon, User);
    move_object(Other, User);
    move_object(Offhand, User);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Offhand);
    destruct(Other);
    destruct(Weapon);
    destruct(Target);
    destruct(Ren);
    destruct(Lian);
    destruct(User);
    destruct(Room);
}

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
void PrepareDisciple(int withRecognition)
{
    ExpectTrue(User.joinGuild("monk"));
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/initiates-discipline.c"));
    AdvanceMonkToLevel(5);
    ExpectFalse(member(User.availableResearchTrees(),
        "/guilds/monk/bludgeon.c") >= 0);
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/disciplined-breath.c"));
    ExpectTrue(User.advanceRank("monk"));
    if (withRecognition)
    {
        ExpectTrue(User.learnResearchFrom(Lian,
            "/guilds/monk/discipline/steady-practice.c"));
        ExpectTrue(User.learnResearchFrom(Lian,
            "/guilds/monk/discipline/teachers-recognition.c"));
    }
    AdvanceMonkToLevel(10);
    ExpectTrue(member(User.availableResearchTrees(),
        "/guilds/monk/bludgeon.c") >= 0);
    ExpectTrue(User.isResearched("/guilds/monk/bludgeon/root.c"));
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/students-awareness.c"));
    ExpectFalse(User.canResearch(Impact));
    ExpectTrue(User.advanceRank("monk"));
    User.hitPoints(10000);
    User.spellPoints(10000);
    User.staminaPoints(10000);
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
void InstructionRequiresRecognitionRankAndRenButNotAWeapon()
{
    ExpectFalse(User.canResearch(Impact));
    PrepareDisciple(0);
    int points = User.researchPoints();
    ExpectFalse(User.learnResearchFrom(Ren, Impact));
    ExpectEq(points, User.researchPoints());
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/steady-practice.c"));
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/teachers-recognition.c"));
    move_object(Weapon, Room);
    move_object(Other, Room);
    move_object(Offhand, Room);
    ExpectTrue(User.canResearch(Impact));
    ExpectFalse(User.canResearch(Guard));
    ExpectFalse(User.initiateResearch(Impact));
    ExpectFalse(User.learnResearchFrom(Lian, Impact));
    ExpectTrue(User.executeCommand("lessons from ren"));
    ExpectSubStringMatch("Measured Impact", User.caughtMessage());
    ExpectSubStringMatch("Settled Guard", User.caughtMessage());
    points = User.researchPoints();
    ExpectTrue(User.executeCommand("learn measured impact from ren"));
    ExpectTrue(User.isResearched(Impact));
    ExpectTrue(User.canResearch(Guard));
    ExpectTrue(User.executeCommand("learn settled guard from ren"));
    ExpectTrue(User.isResearched(Guard));
    ExpectEq(points - 4, User.researchPoints());
    ExpectEq(0, User.researchBonusTo("parry"));
}

/////////////////////////////////////////////////////////////////////////////
void RealStaffMaceAndHammerBlueprintsShareTheTechnique()
{
    PrepareDisciple(1);
    ExpectTrue(User.learnResearchFrom(Ren, Impact));
    ReadyKata();
    foreach (string blueprint in ({ "staff", "quarterstaff", "club",
        "mace", "flanged mace", "morning star", "war hammer" }))
    {
        destruct(Weapon);
        Weapon = clone_object("/lib/items/weapon.c");
        Weapon.set("blueprint", blueprint);
        Weapon.set("name", "implement");
        move_object(Weapon, User);
        ExpectTrue(Weapon.equip("implement"));
        ExpectEq(Weapon, User.equipmentInSlot("wielded primary"));
        if (Weapon.query("weapon type") == "staff")
        {
            ExpectEq(Weapon, User.equipmentInSlot("wielded offhand"));
        }
        int health = Target.hitPoints();
        ExpectTrue(User.executeCommand(KataCommand));
        ExpectTrue(Target.hitPoints() < health);
        ExpectEq(1, User.countObservations(([
            "type":"combat.kata",
            "research":Impact,
            "weapon":blueprint,
            "qualifying opponent":1
        ])));
        ReadyKata();
        ExpectTrue(Weapon.unequip("implement"));
    }
    ExpectEq(7, User.countObservations(([
        "type":"combat.kata", "research":Impact
    ])));
}

/////////////////////////////////////////////////////////////////////////////
void PrimaryFamilyIsRequiredButTheOffhandIsNotRestricted()
{
    PrepareDisciple(1);
    ExpectTrue(User.learnResearchFrom(Ren, Impact));
    ReadyKata();
    int stamina = User.staminaPoints();
    ExpectFalse(User.executeCommand(KataCommand));
    ExpectFalse(load_object(Impact).execute(KataCommand, User));
    ExpectTrue(Other.equip("other"));
    ExpectTrue(Weapon.equip("implement offhand"));
    ExpectFalse(User.executeCommand(KataCommand));
    ExpectFalse(load_object(Impact).execute(KataCommand, User));
    ExpectTrue(Other.unequip("other"));
    ExpectFalse(User.executeCommand(KataCommand));
    ExpectEq(stamina, User.staminaPoints());
    ExpectFalse(User.blockedByCooldown(Impact));
    ExpectEq(0, User.countObservations(([ "type":"combat.kata" ])));
    ExpectTrue(Weapon.unequip("implement"));
    ExpectTrue(Weapon.equip("implement"));
    ExpectTrue(Offhand.equip("dagger offhand"));
    ExpectTrue(User.executeCommand(KataCommand));
    ExpectEq(stamina - 6, User.staminaPoints());
}

/////////////////////////////////////////////////////////////////////////////
void ImpactUsesDamageStaminaActionRecoveryAndExactCooldown()
{
    PrepareDisciple(1);
    ExpectTrue(User.learnResearchFrom(Ren, Impact));
    ExpectTrue(Weapon.equip("implement"));
    ReadyKata();
    int health = Target.hitPoints();
    int mana = User.spellPoints();
    int stamina = User.staminaPoints();
    ExpectTrue(User.executeCommand(KataCommand));
    ExpectTrue(Target.hitPoints() < health);
    ExpectEq(stamina - 6, User.staminaPoints());
    ExpectEq(mana, User.spellPoints());
    ExpectTrue(User.spellAction() > 0);
    ExpectTrue(User.blockedByCooldown(Impact));
    ExpectFalse(User.executeCommand(KataCommand));
    ExpectEq(stamina - 6, User.staminaPoints());
    User.stopFight(Target);
    Target.stopFight(User);
    for (int tick = 0; tick < 3; tick++)
    {
        User.heart_beat();
    }
    ExpectTrue(User.blockedByCooldown(Impact));
    ExpectFalse(User.executeCommand(KataCommand));
    User.heart_beat();
    ExpectFalse(User.blockedByCooldown(Impact));
    ExpectTrue(User.executeCommand(KataCommand));
    ExpectEq(2, User.countObservations(([
        "type":"combat.kata", "research":Impact
    ])));
}

/////////////////////////////////////////////////////////////////////////////
void FollowUpRequiresImpactAndTracksCurrentPrimaryEquipment()
{
    PrepareDisciple(1);
    int points = User.researchPoints();
    ExpectFalse(User.canResearch(Guard));
    ExpectFalse(User.learnResearchFrom(Ren, Guard));
    ExpectTrue(User.learnResearchFrom(Ren, Impact));
    ExpectFalse(User.initiateResearch(Guard));
    ExpectTrue(User.learnResearchFrom(Ren, Guard));
    ExpectEq(points - 4, User.researchPoints());
    ExpectEq(0, User.researchBonusTo("parry"));
    ExpectTrue(Weapon.equip("implement"));
    ExpectEq(1, User.researchBonusTo("parry"));
    ExpectTrue(Offhand.equip("dagger offhand"));
    ExpectEq(1, User.researchBonusTo("parry"));
    ExpectTrue(Weapon.unequip("implement"));
    ExpectEq(0, User.researchBonusTo("parry"));
    ExpectTrue(Offhand.unequip("dagger"));
    ExpectTrue(Other.equip("other"));
    ExpectTrue(Weapon.equip("implement offhand"));
    ExpectEq(0, User.researchBonusTo("parry"));
    int respect = Ren.relationshipValue(User, "respect");
    int lessons = User.countObservations(([ "type":"training.completed" ]));
    ExpectFalse(User.learnResearchFrom(Ren, Guard));
    ExpectEq(points - 4, User.researchPoints());
    ExpectEq(respect, Ren.relationshipValue(User, "respect"));
    ExpectEq(lessons, User.countObservations(([
        "type":"training.completed"
    ])));
}

/////////////////////////////////////////////////////////////////////////////
void OffhandEquipmentReplacesTwoHandedStaffThroughNormalSlotRules()
{
    PrepareDisciple(1);
    ExpectTrue(User.learnResearchFrom(Ren, Impact));
    ExpectTrue(User.learnResearchFrom(Ren, Guard));
    destruct(Weapon);
    Weapon = clone_object("/lib/items/weapon.c");
    Weapon.set("blueprint", "staff");
    Weapon.set("name", "implement");
    move_object(Weapon, User);
    ExpectTrue(Weapon.equip("implement"));
    ExpectEq(Weapon, User.equipmentInSlot("wielded primary"));
    ExpectEq(Weapon, User.equipmentInSlot("wielded offhand"));
    ExpectEq(1, User.researchBonusTo("parry"));
    ReadyKata();
    ExpectTrue(Offhand.equip("dagger offhand"));
    ExpectFalse(User.equipmentInSlot("wielded primary"));
    ExpectEq(Offhand, User.equipmentInSlot("wielded offhand"));
    ExpectEq(0, User.researchBonusTo("parry"));
    ExpectFalse(User.executeCommand(KataCommand));
    ExpectTrue(Weapon.equip("implement"));
    ExpectEq(Weapon, User.equipmentInSlot("wielded offhand"));
    ExpectEq(1, User.researchBonusTo("parry"));
    ExpectTrue(User.executeCommand(KataCommand));
}

/////////////////////////////////////////////////////////////////////////////
void BroadFamilyFollowsLiveTypesRatherThanBlueprintOrDamage()
{
    PrepareDisciple(1);
    ExpectTrue(User.learnResearchFrom(Ren, Impact));
    ExpectTrue(User.learnResearchFrom(Ren, Guard));
    ExpectTrue(Weapon.equip("implement"));
    ReadyKata();
    Weapon.set("weapon type", "long sword");
    ExpectEq("mace", Weapon.query("blueprint"));
    ExpectEq(({ "bludgeon" }), Weapon.query("damage type"));
    ExpectEq(0, User.researchBonusTo("parry"));
    int stamina = User.staminaPoints();
    ExpectFalse(User.executeCommand(KataCommand));
    ExpectFalse(load_object(Impact).execute(KataCommand, User));
    ExpectEq(stamina, User.staminaPoints());
    Weapon.set("weapon type", "hammer");
    ExpectEq(1, User.researchBonusTo("parry"));
    ExpectTrue(User.executeCommand(KataCommand));
    ExpectTrue(User.isResearched(Impact));
    ExpectEq(1, User.countObservations(([
        "type":"combat.kata", "research":Impact
    ])));
}

/////////////////////////////////////////////////////////////////////////////
void KnowledgeTargetAndExactResourceThresholdAreEnforced()
{
    PrepareDisciple(1);
    ExpectTrue(Weapon.equip("implement"));
    ReadyKata();
    ExpectFalse(User.executeCommand(KataCommand));
    ExpectFalse(load_object(Impact).execute(KataCommand, User));
    ExpectTrue(User.learnResearchFrom(Ren, Impact));
    int stamina = User.staminaPoints();
    ExpectFalse(User.executeCommand("kata measured impact at missing"));
    ExpectEq(stamina, User.staminaPoints());
    ReadyKata();
    User.staminaPoints(5 - User.staminaPoints());
    ExpectEq(5, User.staminaPoints());
    ExpectFalse(User.executeCommand(KataCommand));
    ExpectEq(5, User.staminaPoints());
    ExpectEq(0, User.countObservations(([ "type":"combat.kata" ])));
    User.staminaPoints(10000);
    User.staminaPoints(6 - User.staminaPoints());
    ExpectEq(6, User.staminaPoints());
    ExpectTrue(User.executeCommand(KataCommand));
    ExpectEq(0, User.staminaPoints());
}

/////////////////////////////////////////////////////////////////////////////
void ControlledExpenditureUsesTheExistingStaminaReduction()
{
    PrepareDisciple(1);
    ExpectTrue(User.learnResearchFrom(Ren,
        "/guilds/monk/discipline/controlled-expenditure.c"));
    ExpectTrue(User.learnResearchFrom(Ren, Impact));
    ExpectTrue(Weapon.equip("implement"));
    ReadyKata();
    int stamina = User.staminaPoints();
    ExpectTrue(User.executeCommand(KataCommand));
    ExpectEq(stamina - 5, User.staminaPoints());
}

/////////////////////////////////////////////////////////////////////////////
void BludgeonAndUnarmedPracticeRemainSeparate()
{
    string palm = "/guilds/monk/unarmed/measured-palm.c";
    PrepareDisciple(1);
    ExpectTrue(User.learnResearchFrom(Lian, palm));
    ExpectTrue(User.learnResearchFrom(Ren, Impact));
    ReadyKata();
    ExpectTrue(User.executeCommand("kata measured palm at opponent"));
    ExpectEq(0, User.countObservations(([
        "type":"combat.kata", "research":Impact
    ])));
    ReadyKata();
    ExpectTrue(Weapon.equip("implement"));
    ExpectTrue(User.executeCommand(KataCommand));
    ExpectEq(1, User.countObservations(([
        "type":"combat.kata", "research":Impact, "weapon":"mace"
    ])));
    ExpectEq(1, User.countObservations(([
        "type":"combat.kata", "research":palm
    ])));
}
