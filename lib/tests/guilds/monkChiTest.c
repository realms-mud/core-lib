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
string Pulse = "/guilds/monk/pure-chi/focused-pulse.c";
string Ward = "/guilds/monk/mana-shield/mindful-ward.c";
string WardTrait = "/guilds/monk/mana-shield/ward-trait.c";
string PulseCommand = "chi focused pulse at opponent";
string WardCommand = "chi mindful ward";

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    load_object("/guilds/monk/monk.c");
    ignoreList += ({
        "AdvanceMonkToLevel", "PrepareDisciple", "ClearRecovery"
    });
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
    Target.effectiveLevel(10);
    Target.setMaxHitPoints(10000);
    move_object(User, Room);
    move_object(Lian, Room);
    move_object(Ren, Room);
    move_object(Target, Room);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
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
    AdvanceMonkToLevel(10);
    ExpectTrue(member(User.availableResearchTrees(),
        "/guilds/monk/pure-chi.c") >= 0);
    ExpectTrue(member(User.availableResearchTrees(),
        "/guilds/monk/mana-shield.c") >= 0);
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
    AdvanceMonkToLevel(20);
    ExpectTrue(member(User.availableResearchTrees(),
        "/guilds/monk/pure-chi.c") >= 0);
    ExpectTrue(member(User.availableResearchTrees(),
        "/guilds/monk/mana-shield.c") >= 0);
    ExpectTrue(User.isResearched("/guilds/monk/pure-chi/root.c"));
    ExpectTrue(User.isResearched("/guilds/monk/mana-shield/root.c"));
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/students-awareness.c"));
    ExpectTrue(User.canResearch(Pulse));
    ExpectTrue(User.canResearch(Ward));
    ExpectTrue(User.advanceRank("monk"));
    User.hitPoints(10000);
    User.spellPoints(10000);
    User.staminaPoints(10000);
}

/////////////////////////////////////////////////////////////////////////////
void ClearRecovery()
{
    User.stopFight(Target);
    Target.stopFight(User);
    for (int tick = 0; tick < 4; tick++)
    {
        User.heart_beat();
    }
}

/////////////////////////////////////////////////////////////////////////////
void InitialLessonsRequireFoundationsAndTheCorrectTeacher()
{
    ExpectFalse(User.canResearch(Pulse));
    ExpectFalse(User.canResearch(Ward));
    PrepareDisciple(0);
    int points = User.researchPoints();
    ExpectTrue(User.canResearch(Pulse));
    ExpectTrue(User.canResearch(Ward));
    ExpectEq(points, User.researchPoints());
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/steady-practice.c"));
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/teachers-recognition.c"));
    ExpectTrue(User.canResearch(Pulse));
    ExpectTrue(User.canResearch(Ward));
    ExpectFalse(User.initiateResearch(Pulse));
    ExpectFalse(User.initiateResearch(Ward));
    ExpectFalse(User.learnResearchFrom(Lian, Pulse));
    ExpectFalse(User.learnResearchFrom(Lian, Ward));
    points = User.researchPoints();
    ExpectTrue(User.executeCommand("lessons from ren"));
    ExpectSubStringMatch("Focused Pulse", User.caughtMessage());
    ExpectSubStringMatch("Mindful Ward", User.caughtMessage());
    ExpectTrue(User.executeCommand("learn focused pulse from ren"));
    ExpectTrue(User.isResearched(Pulse));
    ExpectTrue(User.executeCommand("learn mindful ward from ren"));
    ExpectTrue(User.isResearched(Ward));
    ExpectEq(points - 4, User.researchPoints());
    ExpectEq(4, Ren.relationshipValue(User, "respect"));
    ExpectFalse(User.learnResearchFrom(Ren, Pulse));
    ExpectFalse(User.learnResearchFrom(Ren, Ward));
    ExpectEq(points - 4, User.researchPoints());
    ExpectEq(4, Ren.relationshipValue(User, "respect"));
}

/////////////////////////////////////////////////////////////////////////////
void PulseSpendsSpellPointsAndUsesExactCooldownWithoutKataPractice()
{
    PrepareDisciple(1);
    ExpectTrue(User.learnResearchFrom(Ren, Pulse));
    int health = Target.hitPoints();
    int mana = User.spellPoints();
    int stamina = User.staminaPoints();
    ExpectTrue(User.executeCommand(PulseCommand));
    ExpectTrue(Target.hitPoints() < health);
    ExpectEq(mana - 6, User.spellPoints());
    ExpectEq(stamina, User.staminaPoints());
    ExpectTrue(User.spellAction() > 0);
    ExpectTrue(User.blockedByCooldown(Pulse));
    ExpectEq(1, User.countObservations(([
        "type":"research.use", "research":Pulse
    ])));
    ExpectEq(0, User.countObservations(([ "type":"combat.kata" ])));
    ExpectFalse(User.executeCommand(PulseCommand));
    ExpectEq(mana - 6, User.spellPoints());
    User.stopFight(Target);
    Target.stopFight(User);
    for (int tick = 0; tick < 3; tick++)
    {
        User.heart_beat();
    }
    ExpectTrue(User.blockedByCooldown(Pulse));
    ExpectFalse(User.executeCommand(PulseCommand));
    User.heart_beat();
    ExpectFalse(User.blockedByCooldown(Pulse));
    ExpectTrue(User.executeCommand(PulseCommand));
    ExpectEq(2, User.countObservations(([
        "type":"research.use", "research":Pulse
    ])));
}

/////////////////////////////////////////////////////////////////////////////
void PulseChecksKnowledgeTargetEnergyAndSharedActionRecovery()
{
    PrepareDisciple(1);
    ExpectFalse(User.executeCommand(PulseCommand));
    ExpectFalse(load_object(Pulse).execute(PulseCommand, User));
    ExpectTrue(User.learnResearchFrom(Ren, Pulse));
    ExpectTrue(User.learnResearchFrom(Ren, Ward));
    int mana = User.spellPoints();
    ExpectFalse(User.executeCommand("chi focused pulse at missing"));
    ExpectEq(mana, User.spellPoints());
    ClearRecovery();
    User.spellPoints(-User.spellPoints());
    User.spellPoints(5);
    ExpectFalse(User.executeCommand(PulseCommand));
    ExpectEq(5, User.spellPoints());
    ExpectEq(0, User.countObservations(([
        "type":"research.use", "research":Pulse
    ])));
    User.spellPoints(1);
    ExpectTrue(User.executeCommand(PulseCommand));
    ExpectEq(0, User.spellPoints());
    int maximum = User.maxStaminaPoints();
    ExpectFalse(User.executeCommand(WardCommand));
    ExpectFalse(User.sustainedResearchIsActive(Ward));
    ExpectEq(maximum, User.maxStaminaPoints());
    ExpectEq(0, User.countObservations(([
        "type":"research.use", "subject":Ward
    ])));
}

/////////////////////////////////////////////////////////////////////////////
void WardReservesStaminaAndAbsorbsOnlyPostMitigationDamage()
{
    PrepareDisciple(1);
    ExpectTrue(User.learnResearchFrom(Ren, Ward));
    mapping damage = ([
        "physical":User.hit(30, "physical", Target),
        "fire":User.hit(30, "fire", Target)
    ]);
    User.hitPoints(10000);
    int health = User.hitPoints();
    int mana = User.spellPoints();
    int maximum = User.maxStaminaPoints();
    int maximumMana = User.maxSpellPoints();
    ExpectTrue(User.executeCommand(WardCommand));
    ExpectTrue(User.sustainedResearchIsActive(Ward));
    ExpectTrue(User.hasTraitOfRoot("mana shield"));
    ExpectEq(maximum - 10, User.maxStaminaPoints());
    ExpectEq(maximumMana, User.maxSpellPoints());
    ExpectEq(mana, User.spellPoints());
    foreach (string type in ({ "physical", "fire" }))
    {
        ExpectTrue(damage[type] > 0);
        ExpectEq(0, User.hit(30, type, Target));
        mana -= damage[type];
        ExpectEq(mana, User.spellPoints());
        ExpectEq(health, User.hitPoints());
    }
}

/////////////////////////////////////////////////////////////////////////////
void DepletedWardSpillsToHpAndResumesWhenManaRecovers()
{
    PrepareDisciple(1);
    ExpectTrue(User.learnResearchFrom(Ren, Ward));
    int damage = User.hit(30, "physical", Target);
    ExpectTrue(damage > 10);
    User.hitPoints(10000);
    int health = User.hitPoints();
    ExpectTrue(User.executeCommand(WardCommand));
    User.spellPoints(-User.spellPoints());
    User.spellPoints(5);
    ExpectEq(damage - 5, User.hit(30, "physical", Target));
    health -= damage - 5;
    ExpectEq(health, User.hitPoints());
    ExpectEq(0, User.spellPoints());
    ExpectTrue(User.sustainedResearchIsActive(Ward));
    ExpectEq(damage, User.hit(30, "physical", Target));
    health -= damage;
    ExpectEq(health, User.hitPoints());
    User.spellPoints(10);
    ExpectEq(damage - 10, User.hit(30, "physical", Target));
    ExpectEq(health - damage + 10, User.hitPoints());
    ExpectEq(0, User.spellPoints());
    ExpectTrue(User.sustainedResearchIsActive(Ward));
    ExpectEq(1, User.countObservations(([
        "type":"research.use", "subject":Ward
    ])));
}

/////////////////////////////////////////////////////////////////////////////
void TurningWardOffImmediatelyRemovesProtectionWithoutManaRefund()
{
    PrepareDisciple(1);
    ExpectTrue(User.learnResearchFrom(Ren, Ward));
    int damage = User.hit(30, "physical", Target);
    User.hitPoints(10000);
    int health = User.hitPoints();
    int maximum = User.maxStaminaPoints();
    ExpectTrue(User.executeCommand(WardCommand));
    User.spellPoints(-11);
    int mana = User.spellPoints();
    ExpectTrue(User.executeCommand(WardCommand));
    ExpectFalse(User.sustainedResearchIsActive(Ward));
    ExpectFalse(User.isTraitOf(WardTrait));
    ExpectFalse(User.hasTraitOfRoot("mana shield"));
    ExpectEq(maximum, User.maxStaminaPoints());
    ExpectEq(mana, User.spellPoints());
    ExpectEq(damage, User.hit(30, "physical", Target));
    ExpectEq(health - damage, User.hitPoints());
    ExpectEq(mana, User.spellPoints());
    ExpectFalse(User.executeCommand(WardCommand));
    User.stopFight(Target);
    Target.stopFight(User);
    User.heart_beat();
    ExpectTrue(User.blockedByCooldown(Ward));
    ExpectFalse(User.executeCommand(WardCommand));
    User.heart_beat();
    ExpectFalse(User.blockedByCooldown(Ward));
    ExpectTrue(User.executeCommand(WardCommand));
    ExpectEq(maximum - 10, User.maxStaminaPoints());
    ClearRecovery();
    ExpectEq(2, User.countObservations(([
        "type":"research.use", "subject":Ward
    ])));
    ExpectEq(1, User.countObservations(([
        "type":"research.deactivated", "subject":Ward
    ])));
}

/////////////////////////////////////////////////////////////////////////////
void OtherManaShieldSourcesDoNotMultiplyOrGetRemovedWithTheWard()
{
    string other = "/lib/tests/support/traits/testManaShieldTrait.c";
    PrepareDisciple(1);
    ExpectTrue(User.learnResearchFrom(Ren, Ward));
    int damage = User.hit(30, "physical", Target);
    User.hitPoints(10000);
    int health = User.hitPoints();
    int mana = User.spellPoints();
    ExpectTrue(User.addTrait(other));
    ExpectTrue(User.executeCommand(WardCommand));
    ExpectEq(0, User.hit(30, "physical", Target));
    ExpectEq(mana - damage, User.spellPoints());
    ExpectEq(health, User.hitPoints());
    ExpectTrue(User.executeCommand(WardCommand));
    ExpectFalse(User.isTraitOf(WardTrait));
    ExpectTrue(User.isTraitOf(other));
    ExpectTrue(User.hasTraitOfRoot("mana shield"));
    ExpectEq(0, User.hit(30, "physical", Target));
    ExpectEq(mana - 2 * damage, User.spellPoints());
    ExpectEq(health, User.hitPoints());
}

/////////////////////////////////////////////////////////////////////////////
void OffenseAndDefenseConsumeTheSamePoolWithoutExtraUpkeep()
{
    PrepareDisciple(1);
    ExpectTrue(User.learnResearchFrom(Ren, Pulse));
    ExpectTrue(User.learnResearchFrom(Ren, Ward));
    int damage = User.hit(30, "physical", Target);
    User.hitPoints(10000);
    ExpectTrue(User.executeCommand(WardCommand));
    ClearRecovery();
    User.spellPoints(-User.spellPoints());
    User.spellPoints(60);
    int health = User.hitPoints();
    ExpectTrue(User.executeCommand(PulseCommand));
    ExpectEq(54, User.spellPoints());
    ExpectEq(0, User.hit(30, "physical", Target));
    ExpectEq(54 - damage, User.spellPoints());
    ExpectEq(health, User.hitPoints());
    ClearRecovery();
    User.spellPoints(-User.spellPoints());
    ExpectFalse(User.executeCommand(PulseCommand));
    ExpectTrue(User.sustainedResearchIsActive(Ward));
    ExpectEq(1, User.countObservations(([
        "type":"research.use", "research":Pulse
    ])));
    ExpectEq(1, User.countObservations(([
        "type":"research.use", "subject":Ward
    ])));
}
