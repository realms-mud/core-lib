//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/support/guilds/monkTrialFixture.c";

object User;
object Room;
object Lian;
object Ren;
object Target;
object Formula;
int StudentNumber;
string Base = "/guilds/monk/unarmed/";
mapping Lessons = ([
    "measured-palm":1,
    "balanced-recovery":2,
    "open-hand-guard":3,
    "quiet-footwork":4,
    "joint-conditioning":5,
    "hand-alignment":6,
    "guarded-breath":7,
    "driving-elbow":8,
    "elbow-anatomy":9,
    "crane-stance":10,
    "grounded-base":12,
    "centering-breath":14,
    "disrupting-knee":16,
    "knee-leverage":18,
    "centered-vitality":20,
    "tiger-stance":22,
    "supple-form":24,
    "rising-heel":26,
    "heel-trajectory":28,
    "hammer-fist":30,
    "fist-compression":32,
    "patient-recovery":34,
    "restorative-breath":36,
    "sapping-palm":38,
    "meridian-lore":40,
    "stone-stance":42,
    "breath-economy":44,
    "crushing-embrace":46,
    "grappling-mechanics":48,
    "meridian-strike":50,
    "vital-reading":52,
    "flowing-stance":54,
    "iron-body":56,
    "empty-hand":58,
    "empty-hand-theory":60,
    "pulse-mapping":62,
    "finishing-economy":64,
    "returning-breath":66,
    "returning-rhythm":68,
    "still-heart":70
]);

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    load_object("/guilds/monk/monk.c");
    ignoreList += ({ "TeachMonkTrialLesson", "CompleteMonkUpperTrial",
        "JoinAndLearnPalm", "CheckPrerequisiteChain" });
    Room = clone_object("/lib/environment/environment.c");
    Lian = clone_object("/guilds/monk/teachers/lian.c");
    Ren = clone_object("/guilds/monk/teachers/ren.c");
    move_object(Lian, Room);
    move_object(Ren, Room);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name(sprintf("progression%d", ++StudentNumber));
    User.Race("human");
    User.Str(20);
    User.Dex(20);
    User.Int(20);
    User.Wis(20);
    User.Con(20);
    User.colorConfiguration("none");
    move_object(User, Room);
    Target = clone_object("/lib/realizations/npc.c");
    Target.Name("opponent");
    Target.Race("human");
    Target.effectiveLevel(1);
    Target.setMaxHitPoints(10000);
    move_object(Target, Room);
    Formula = clone_object("/lib/tests/support/research/testEffectModifier.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Formula);
    destruct(Target);
    destruct(User);
}

/////////////////////////////////////////////////////////////////////////////
void TearDown()
{
    destruct(Ren);
    destruct(Lian);
    destruct(Room);
}

/////////////////////////////////////////////////////////////////////////////
void JoinAndLearnPalm()
{
    ExpectTrue(User.joinGuild("monk"));
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/disciplined-breath.c"));
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/initiates-discipline.c"));
    ExpectTrue(User.learnResearchFrom(Lian, Base + "measured-palm.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CheckPrerequisiteChain(string path, int level, string rank)
{
    object item = getService("research")->researchObject(path);
    foreach(string key, mapping requirement in item.getPrerequisites())
    {
        if (requirement["type"] == "level" && requirement["guild"] == "monk")
        {
            ExpectTrue(requirement["value"] <= level,
                path + " has no hidden later level requirement");
        }
        else if (requirement["type"] == "guild rank" &&
            requirement["guild"] == "monk")
        {
            ExpectTrue(member(requirement["value"], rank) >= 0,
                path + " permits " + rank);
        }
        else if (requirement["type"] == "research")
        {
            CheckPrerequisiteChain(key, level, rank);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void FortyDistinctLessonLevelsRunFromOneThroughSeventy()
{
    object tree = getService("research")->researchTree(
        "/guilds/monk/unarmed.c");
    ExpectEq(41, sizeof(tree.getFlattenedResearchTree()));
    mapping levels = ([]);
    foreach(string lesson, int level in Lessons)
    {
        object item = tree.getResearchItem(Base + lesson + ".c");
        ExpectEq(level, item.getPrerequisites()["level"]["value"], lesson);
        ExpectFalse(member(levels, level), lesson + " distinct level");
        levels[level] = 1;
        string rank = level < 10 ? "initiate" :
            level < 20 ? "student" : level < 30 ? "disciple" :
            level < 40 ? "adept" : level < 55 ? "senior disciple" :
            level < 70 ? "master candidate" : "master";
        CheckPrerequisiteChain(Base + lesson + ".c", level, rank);
    }
    ExpectEq(40, sizeof(levels));
    ExpectTrue(member(levels, 1));
    ExpectTrue(member(levels, 70));
    for (int level = 1; level < 70; level++)
    {
        ExpectTrue(member(levels, level) || member(levels, level + 1),
            sprintf("Training within levels %d-%d", level, level + 1));
    }
}

/////////////////////////////////////////////////////////////////////////////
void InitiatesCanLearnAndExecutePalmAtLevelOneWithNaturalPoints()
{
    JoinAndLearnPalm();
    ExpectEq(1, User.guildLevel("monk"));
    ExpectEq("initiate", User.guildRank("monk"));
    ExpectTrue(User.researchPoints() >= 0);
    User.staminaPoints(10000);
    ExpectTrue(User.staminaPoints() >= 6);
    ExpectTrue(Target.registerAttacker(User));
    ExpectTrue(User.registerAttacker(Target));
    int stamina = User.staminaPoints();
    int health = Target.hitPoints();
    ExpectTrue(User.executeCommand("kata measured palm at opponent"));
    ExpectEq(stamina - 6, User.staminaPoints());
    ExpectTrue(Target.hitPoints() < health);
    ExpectEq(1, User.countObservations(([
        "type":"combat.kata",
        "research":Base + "measured-palm.c",
        "qualifying opponent":1
    ])));
}

/////////////////////////////////////////////////////////////////////////////
void PromotionRoutesAreLearnableBeforeTheirDestinationRank()
{
    string *trials = ({ "senior-disciples-trial",
        "master-candidates-trial", "masters-trial" });
    int *levels = ({ 40, 55, 70 });
    string *ranks = ({ "adept", "senior disciple", "master candidate" });
    for (int index = 0; index < sizeof(trials); index++)
    {
        object trial = load_object("/guilds/monk/discipline/" +
            trials[index] + ".c");
        mapping route = trial.getPrerequisites()["specialist mastery"]
            ["prerequisites"][0];
        foreach(string path, mapping requirement in route)
        {
            if (requirement["type"] == "research")
            {
                CheckPrerequisiteChain(path, levels[index], ranks[index]);
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void EveryKnowledgeBonusIsWiredIntoItsReceivingFormula()
{
    object tree = getService("research")->researchTree(
        "/guilds/monk/unarmed.c");
    foreach(object knowledge in m_indices(tree.getFlattenedResearchTree()))
    {
        if (knowledge.query("affected research type") == "bonus")
        {
            foreach(string name, int bonus in
                knowledge.query("affected research"))
            {
                object receiver = 0;
                foreach(object item in
                    m_indices(tree.getFlattenedResearchTree()))
                {
                    if (item.query("name") == name)
                    {
                        receiver = item;
                    }
                }
                ExpectTrue(objectp(receiver), name);
                if (receiver)
                {
                    mapping *modifiers = ({});
                    foreach(mapping modifier in receiver.query("modifiers"))
                    {
                        if (modifier["type"] == "research" &&
                            modifier["research item"] == program_name(knowledge))
                        {
                            modifiers += ({ modifier });
                        }
                    }
                    ExpectEq(1, sizeof(modifiers), name);
                    if (sizeof(modifiers) == 1)
                    {
                        ExpectEq("additive", modifiers[0]["formula"], name);
                        ExpectEq(bonus, to_int(modifiers[0]["rate"] *
                            modifiers[0]["base value"]), name);
                    }
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void EveryActiveFormulaUsesSkillsAttributesAndMultipleResearchLessons()
{
    object tree = getService("research")->researchTree(
        "/guilds/monk/unarmed.c");
    foreach(object item in m_indices(tree.getFlattenedResearchTree()))
    {
        if (item.query("type") == "active")
        {
            mapping counts = ([]);
            mapping distinct = ([]);
            foreach(mapping modifier in item.query("modifiers"))
            {
                ExpectTrue(Formula.testIsValidModifier(modifier),
                    item.query("name"));
                string key = modifier["type"] + ":" +
                    (modifier["type"] == "research" ?
                        modifier["research item"] : modifier["name"]);
                ExpectFalse(member(distinct, key), key);
                distinct[key] = 1;
                counts[modifier["type"]]++;
            }
            ExpectTrue(counts["skill"] >= 2, item.query("name"));
            ExpectTrue(counts["attribute"] >= 3, item.query("name"));
            ExpectTrue(counts["research"] >= 3, item.query("name"));
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void AdditionalSkillsAndAttributesChangeRealDrivingElbowDamage()
{
    object elbow = load_object(Base + "driving-elbow.c");
    User.addSkillPoints(10000);
    int before = elbow.getEffectsToApply(User)["effects"]["damage hit points"];
    int anatomy = User.getSkill("anatomy and physiology");
    ExpectTrue(User.advanceSkill("anatomy and physiology", 20));
    int expected = to_int(User.getSkill("anatomy and physiology") * 0.1) -
        to_int(anatomy * 0.1);
    ExpectTrue(expected > 0);
    ExpectEq(before + expected,
        elbow.getEffectsToApply(User)["effects"]["damage hit points"]);
    before = elbow.getEffectsToApply(User)["effects"]["damage hit points"];
    int physics = User.getSkill("physics");
    ExpectTrue(User.advanceSkill("physics", 20));
    expected = to_int(User.getSkill("physics") * 0.1) -
        to_int(physics * 0.1);
    ExpectTrue(expected > 0);
    ExpectEq(before + expected,
        elbow.getEffectsToApply(User)["effects"]["damage hit points"]);
    before = elbow.getEffectsToApply(User)["effects"]["damage hit points"];
    int dexterity = User.attributeValue("dexterity");
    User.Dex(30);
    expected = to_int(User.attributeValue("dexterity") * 0.1) -
        to_int(dexterity * 0.1);
    ExpectTrue(expected > 0);
    ExpectEq(before + expected,
        elbow.getEffectsToApply(User)["effects"]["damage hit points"]);
}

/////////////////////////////////////////////////////////////////////////////
void AllFortyLessonsAreTaughtAtTheirAuthoredLevelsThroughRealPromotions()
{
    JoinAndLearnPalm();
    User.addResearchPoints(1000);
    for (int use = 0; use < 10; use++)
    {
        ExpectTrue(mappingp(User.recordObservation(([
            "type":"combat.kata",
            "context":([
                "research":Base + "measured-palm.c",
                "qualifying opponent":1
            ])
        ]), 1)));
    }
    mapping promotions = ([
        10:"disciplined-breath",
        20:"students-awareness",
        30:"disciples-insight",
        40:"adepts-focus",
        55:"inner-discipline",
        70:"mastery-of-fundamentals"
    ]);
    mapping trials = ([
        40:0,
        55:1,
        70:2
    ]);
    for (int level = 2; level <= 70; level++)
    {
        User.addExperience(User.experienceToNextLevel("monk"), "monk");
        ExpectTrue(User.advanceLevel("monk"));
        ExpectEq(level, User.guildLevel("monk"));
        if (level == 2)
        {
            ExpectTrue(User.learnResearchFrom(Lian,
                "/guilds/monk/discipline/steady-practice.c"));
        }
        if (level == 3)
        {
            ExpectTrue(User.learnResearchFrom(Lian,
                "/guilds/monk/discipline/teachers-recognition.c"));
        }
        if (member(promotions, level))
        {
            string foundation = "/guilds/monk/discipline/" +
                promotions[level] + ".c";
            if (!User.isResearched(foundation))
            {
                ExpectTrue(User.initiateResearch(foundation), foundation);
            }
            if (level == 30)
            {
                ExpectTrue(User.learnResearchFrom(Ren,
                    "/guilds/monk/discipline/adepts-trial.c"));
            }
            if (member(trials, level))
            {
                CompleteMonkUpperTrial(User, Lian, Ren, trials[level]);
            }
            ExpectTrue(User.advanceRank("monk"));
        }
        foreach(string lesson, int available in Lessons)
        {
            string path = Base + lesson + ".c";
            if (available == level && !User.isResearched(path))
            {
                TeachMonkTrialLesson(User, ({ Lian, Ren }), path);
            }
        }
    }
    ExpectEq("master", User.guildRank("monk"));
    foreach(string lesson in m_indices(Lessons))
    {
        ExpectTrue(User.isResearched(Base + lesson + ".c"), lesson);
    }
}
