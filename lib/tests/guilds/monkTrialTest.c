//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object User;
object Lian;
object Ren;
object Sora;
object Iori;
object Arrows;
object Room;
object Target;
object Weapon;
object Companion;
int StudentNumber;
string Trial = "/guilds/monk/discipline/adepts-trial.c";
string Palm = "/guilds/monk/unarmed/measured-palm.c";
string Cut = "/guilds/monk/katana/measured-cut.c";
string Impact = "/guilds/monk/bludgeon/measured-impact.c";
string Pulse = "/guilds/monk/pure-chi/focused-pulse.c";
string Linked = "/guilds/monk/paired-swords/linked-cut.c";
string Committed = "/guilds/monk/odachi/committed-cut.c";
string Draw = "/guilds/monk/archery/measured-draw.c";
string Hook = "/guilds/monk/kama/measured-hook.c";
string Rake = "/guilds/monk/claw/measured-rake.c";

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    load_object("/guilds/monk/monk.c");
    ignoreList += ({ "AdvanceMonkToLevel", "PrepareDisciple",
        "PrepareCandidate", "ReadyPractice", "AddHistoricalPractice",
        "CompleteTrialUsing" });
    Room = clone_object("/lib/environment/environment.c");
    Lian = clone_object("/guilds/monk/teachers/lian.c");
    Ren = clone_object("/guilds/monk/teachers/ren.c");
    Sora = clone_object("/guilds/monk/teachers/sora.c");
    Iori = clone_object("/guilds/monk/teachers/iori.c");
    foreach(object teacher in ({ Lian, Ren, Sora, Iori }))
    {
        move_object(teacher, Room);
    }
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name(sprintf("candidate%d", ++StudentNumber));
    User.Str(20);
    User.Int(20);
    User.Dex(20);
    User.Con(20);
    User.Wis(20);
    User.Chr(20);
    User.Race("human");
    User.colorConfiguration("none");
    Target = clone_object("/lib/realizations/npc.c");
    Target.Name("opponent");
    Target.effectiveLevel(15);
    Target.setMaxHitPoints(10000);
    move_object(User, Room);
    move_object(Target, Room);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    if (Weapon)
    {
        destruct(Weapon);
    }
    if (Companion)
    {
        destruct(Companion);
    }
    if (Arrows)
    {
        destruct(Arrows);
    }
    destruct(Target);
    destruct(User);
}

/////////////////////////////////////////////////////////////////////////////
void TearDown()
{
    destruct(Ren);
    destruct(Sora);
    destruct(Iori);
    destruct(Lian);
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
void PrepareDisciple(int recognized)
{
    ExpectTrue(User.joinGuild("monk"));
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/initiates-discipline.c"));
    AdvanceMonkToLevel(10);
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/disciplined-breath.c"));
    ExpectTrue(User.advanceRank("monk"));
    if (recognized)
    {
        ExpectTrue(User.learnResearchFrom(Lian,
            "/guilds/monk/discipline/steady-practice.c"));
        ExpectTrue(User.learnResearchFrom(Lian,
            "/guilds/monk/discipline/teachers-recognition.c"));
    }
    AdvanceMonkToLevel(20);
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/students-awareness.c"));
    ExpectTrue(User.advanceRank("monk"));
}

/////////////////////////////////////////////////////////////////////////////
void PrepareCandidate()
{
    PrepareDisciple(1);
    AdvanceMonkToLevel(30);
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/disciples-insight.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ReadyPractice()
{
    User.stopFight(Target);
    Target.stopFight(User);
    for (int tick = 0; tick < 10; tick++)
    {
        User.heart_beat();
    }
    User.hitPoints(10000);
    User.staminaPoints(10000);
    User.spellPoints(10000);
    ExpectTrue(Target.registerAttacker(User));
    ExpectTrue(User.registerAttacker(Target));
}

/////////////////////////////////////////////////////////////////////////////
void AddHistoricalPractice(string research, string type, int count,
    int qualifying)
{
    for (int index = 0; index < count; index++)
    {
        ExpectTrue(mappingp(User.recordObservation(([
            "type":type,
            "context":([
                "research":research,
                "qualifying opponent":qualifying
            ])
        ]), 1)));
    }
}

/////////////////////////////////////////////////////////////////////////////
varargs void CompleteTrialUsing(string research, string command,
    string blueprint, string companion)
{
    PrepareCandidate();
    object teacher = (research == Palm || research == Cut) ? Lian :
        member(({ Linked, Committed, Hook, Rake }), research) >= 0 ? Sora :
        research == Draw ? Iori : Ren;
    if (research == Draw)
    {
        Arrows = clone_object("/lib/items/ammunition.c");
        Arrows.set("name", "practice quiver");
        Arrows.set("ammunition type", "arrow");
        Arrows.set("max capacity", 10);
        Arrows.set("quantity", 10);
        move_object(Arrows, User);
    }
    if (research == Linked || research == Committed)
    {
        ExpectTrue(User.learnResearchFrom(Sora, research == Linked ?
            "/guilds/monk/paired-swords/paired-grip.c" :
            "/guilds/monk/odachi/longblade-grip.c"));
    }
    if (research == Hook || research == Rake)
    {
        ExpectTrue(User.learnResearchFrom(Sora, research == Hook ?
            "/guilds/monk/kama/hooked-grip.c" :
            "/guilds/monk/claw/claw-grip.c"));
    }
    ExpectTrue(User.learnResearchFrom(teacher, research));
    if (sizeof(blueprint))
    {
        Weapon = clone_object("/lib/items/weapon.c");
        Weapon.set("blueprint", blueprint);
        Weapon.set("name", "implement");
        move_object(Weapon, User);
        ExpectTrue(Weapon.equip("implement"));
    }
    if (companion)
    {
        Companion = clone_object("/lib/items/weapon.c");
        Companion.set("blueprint", companion);
        Companion.set("name", "companion");
        move_object(Companion, User);
        ExpectTrue(Companion.equip("companion offhand"));
    }
    for (int index = 0; index < 10; index++)
    {
        ExpectFalse(User.canResearch(Trial));
        ExpectFalse(User.advanceRank("monk"));
        ReadyPractice();
        ExpectTrue(User.executeCommand(command));
    }
    ExpectEq(10, User.countObservations(([
        "type":research == Pulse ? "research.use" : "combat.kata",
        "research":research,
        "qualifying opponent":1
    ])));
    ExpectTrue(User.canResearch(Trial));
    ExpectFalse(User.initiateResearch(Trial));
    ExpectFalse(User.learnResearchFrom(Lian, Trial));
    User.stopFight(Target);
    Target.stopFight(User);
    for (int tick = 0; tick < 4; tick++)
    {
        User.heart_beat();
    }
    if (Weapon)
    {
        ExpectTrue(Weapon.unequip("implement"));
    }
    if (Companion)
    {
        ExpectTrue(Companion.unequip("companion"));
    }
    int points = User.researchPoints();
    int respect = Ren.relationshipValue(User, "respect");
    int completed = User.countObservations(([
        "type":"training.completed",
        "research":Trial
    ]));
    ExpectTrue(User.executeCommand("learn adept's trial from ren"));
    ExpectTrue(User.isResearched(Trial));
    ExpectEq("disciple", User.guildRank("monk"));
    ExpectEq(points, User.researchPoints());
    ExpectEq(respect + 2, Ren.relationshipValue(User, "respect"));
    ExpectEq(completed + 1, User.countObservations(([
        "type":"training.completed",
        "research":Trial
    ])));
    ExpectFalse(User.learnResearchFrom(Ren, Trial));
    ExpectEq(points, User.researchPoints());
    ExpectEq(respect + 2, Ren.relationshipValue(User, "respect"));
    ExpectTrue(User.executeCommand("advance with lian"));
    ExpectEq("adept", User.guildRank("monk"));
    ExpectEq(points, User.researchPoints());
    ExpectFalse(User.advanceRank("monk"));
}

/////////////////////////////////////////////////////////////////////////////
void UnarmedPracticeCanCompleteTheTrialWithoutCrossTraining()
{
    CompleteTrialUsing(Palm, "kata measured palm at opponent", "");
}

/////////////////////////////////////////////////////////////////////////////
void KatanaPracticeCanCompleteTheTrialWithoutCrossTraining()
{
    CompleteTrialUsing(Cut, "kata measured cut at opponent", "katana");
}

/////////////////////////////////////////////////////////////////////////////
void BludgeonPracticeCanCompleteTheTrialWithoutCrossTraining()
{
    CompleteTrialUsing(Impact, "kata measured impact at opponent", "mace");
}

/////////////////////////////////////////////////////////////////////////////
void ChiPracticeCanCompleteTheTrialWithoutCrossTraining()
{
    CompleteTrialUsing(Pulse, "chi focused pulse at opponent", "");
}

/////////////////////////////////////////////////////////////////////////////
void PairedPracticeCanCompleteTheTrialWithoutCrossTraining()
{
    CompleteTrialUsing(Linked, "kata linked cut at opponent",
        "katana", "wakisashi");
}

/////////////////////////////////////////////////////////////////////////////
void OdachiPracticeCanCompleteTheTrialWithoutCrossTraining()
{
    CompleteTrialUsing(Committed, "kata committed cut at opponent", "odachi");
}

/////////////////////////////////////////////////////////////////////////////
void ArcheryPracticeCanCompleteTheTrialWithoutCrossTraining()
{
    CompleteTrialUsing(Draw, "kata measured draw at opponent", "long bow");
    ExpectEq(0, Arrows.query("quantity"));
}

/////////////////////////////////////////////////////////////////////////////
void KamaPracticeCanCompleteTheTrialWithoutCrossTraining()
{
    CompleteTrialUsing(Hook, "kata measured hook at opponent", "kama");
}

/////////////////////////////////////////////////////////////////////////////
void ClawPracticeCanCompleteTheTrialWithoutCrossTraining()
{
    CompleteTrialUsing(Rake, "kata measured rake at opponent", "tiger claws");
}

/////////////////////////////////////////////////////////////////////////////
void PartialPracticeAcrossAllNinePathsDoesNotSumIntoCertification()
{
    PrepareCandidate();
    foreach(string path in ({ Palm, Cut, Impact, Pulse, Linked, Committed,
        Draw, Hook, Rake }))
    {
        AddHistoricalPractice(path,
            path == Pulse ? "research.use" : "combat.kata", 9, 1);
    }
    ExpectFalse(User.canResearch(Trial));
    AddHistoricalPractice(Committed, "combat.kata", 1, 1);
    ExpectTrue(User.canResearch(Trial));
}

/////////////////////////////////////////////////////////////////////////////
void TrialRequiresMembershipLevelInsightAndRecognition()
{
    ExpectFalse(User.canResearch(Trial));
    PrepareDisciple(0);
    AddHistoricalPractice(Palm, "combat.kata", 10, 1);
    ExpectFalse(User.canResearch(Trial));
    AdvanceMonkToLevel(30);
    ExpectFalse(User.canResearch(Trial));
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/disciples-insight.c"));
    ExpectFalse(User.canResearch(Trial));
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/steady-practice.c"));
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/teachers-recognition.c"));
    ExpectTrue(User.canResearch(Trial));
    ExpectTrue(User.leaveGuild("monk"));
    ExpectFalse(User.canResearch(Trial));
    ExpectFalse(User.learnResearchFrom(Ren, Trial));
}

/////////////////////////////////////////////////////////////////////////////
void ChiOpeningStrikesAndWeakOpponentsDoNotProvideTrialEvidence()
{
    PrepareCandidate();
    ExpectTrue(User.learnResearchFrom(Ren, Pulse));
    User.spellPoints(10000);
    ExpectTrue(User.executeCommand("chi focused pulse at opponent"));
    mapping criteria = ([
        "type":"research.use",
        "research":Pulse,
        "qualifying opponent":1
    ]);
    ExpectEq(1, User.countObservations(([
        "type":"research.use",
        "research":Pulse
    ])));
    ExpectEq(0, User.countObservations(criteria));
    Target.effectiveLevel(14);
    ReadyPractice();
    ExpectTrue(User.executeCommand("chi focused pulse at opponent"));
    ExpectEq(0, User.countObservations(criteria));
    Target.effectiveLevel(15);
    ReadyPractice();
    ExpectTrue(User.executeCommand("chi focused pulse at opponent"));
    ExpectEq(1, User.countObservations(criteria));
    ExpectFalse(User.canResearch(Trial));
}

/////////////////////////////////////////////////////////////////////////////
void MixedTechniquesWrongEventsAndUnqualifiedUsesDoNotCompleteTrial()
{
    PrepareCandidate();
    AddHistoricalPractice(Palm, "combat.kata", 9, 1);
    AddHistoricalPractice(Cut, "combat.kata", 9, 1);
    AddHistoricalPractice(Impact, "combat.kata", 9, 1);
    AddHistoricalPractice(Pulse, "research.use", 9, 1);
    AddHistoricalPractice(Palm, "combat.kata", 10, 0);
    AddHistoricalPractice(Pulse, "combat.kata", 10, 1);
    AddHistoricalPractice(Palm, "research.use", 10, 1);
    ExpectFalse(User.canResearch(Trial));
    ExpectFalse(User.learnResearchFrom(Ren, Trial));
    ExpectFalse(User.advanceRank("monk"));
    int points = User.researchPoints();
    ExpectTrue(User.executeCommand("advance with lian"));
    ExpectEq("disciple", User.guildRank("monk"));
    ExpectEq(points, User.researchPoints());
    ExpectTrue(User.executeCommand("lessons from ren"));
    ExpectSubStringMatch("Adept's Trial", User.caughtMessage());
    ExpectSubStringMatch("any one of 9 alternatives", User.caughtMessage());
    AddHistoricalPractice(Impact, "combat.kata", 1, 1);
    ExpectTrue(User.canResearch(Trial));
    ExpectFalse(User.advanceRank("monk"));
}

/////////////////////////////////////////////////////////////////////////////
void TrialRequiresNearbyRenAndDoesNotReserveResourcesOrGrantBonuses()
{
    PrepareCandidate();
    AddHistoricalPractice(Palm, "combat.kata", 10, 1);
    move_object(Ren, this_object());
    ExpectFalse(User.learnResearchFrom(Ren, Trial));
    move_object(Ren, Room);
    int points = User.researchPoints();
    int hitPoints = User.maxHitPoints();
    int spellPoints = User.maxSpellPoints();
    int stamina = User.maxStaminaPoints();
    int dodge = User.researchBonusTo("dodge");
    ExpectTrue(User.learnResearchFrom(Ren, Trial));
    ExpectEq(points, User.researchPoints());
    ExpectEq(hitPoints, User.maxHitPoints());
    ExpectEq(spellPoints, User.maxSpellPoints());
    ExpectEq(stamina, User.maxStaminaPoints());
    ExpectEq(dodge, User.researchBonusTo("dodge"));
    ExpectEq("disciple", User.guildRank("monk"));
}
