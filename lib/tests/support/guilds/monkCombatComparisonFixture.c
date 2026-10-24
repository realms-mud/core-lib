//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Room;
object Arena;
object User;
object Target;
object Weapon;
object Arrows;
object *Teachers = ({});
int StudentNumber;
int ResearchSpent;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "RecordPractice", "LearnLesson", "PrepareMonkTrial",
        "AdvanceBuild", "PrepareBuild", "TrainBuild", "LessonClosure",
        "LearnSchool", "DamageAbilities", "MeasureCombat", "CompareBuild" });
    foreach(string guild in ({ "monk", "fighter", "ranger", "aegis-guard" }))
    {
        load_object("/guilds/" + guild + "/" + guild + ".c");
    }
    Room = clone_object("/lib/environment/environment.c");
    Arena = clone_object("/lib/environment/environment.c");
    foreach(string name in ({ "lian", "ren", "sora", "iori" }))
    {
        object teacher = clone_object("/guilds/monk/teachers/" + name + ".c");
        Teachers += ({ teacher });
        move_object(teacher, Room);
    }
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    foreach(object item in ({ Arrows, Weapon, Target, User }))
    {
        if (objectp(item))
        {
            destruct(item);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void TearDown()
{
    foreach(object teacher in Teachers)
    {
        destruct(teacher);
    }
    destruct(Room);
    destruct(Arena);
}

/////////////////////////////////////////////////////////////////////////////
void RecordPractice(mapping requirement)
{
    mapping criteria = requirement["criteria"];
    mapping context = criteria + ([]);
    m_delete(context, "type");
    for (int use = 0; use < requirement["value"]; use++)
    {
        ExpectTrue(mappingp(User.recordObservation(([
            "type":criteria["type"],
            "context":context
        ]), 1)));
    }
}

/////////////////////////////////////////////////////////////////////////////
void LearnLesson(string path)
{
    if (!User.isResearched(path))
    {
        object lesson = getService("research")->researchObject(path);
        foreach(string prerequisite, mapping requirement in
            lesson.getPrerequisites())
        {
            if (requirement["type"] == "research")
            {
                LearnLesson(prerequisite);
            }
            else if (requirement["type"] == "observation" &&
                mappingp(requirement["criteria"]))
            {
                RecordPractice(requirement);
            }
        }
        int before = User.researchPoints();
        int learned = 0;
        if (lesson.query("teacher required"))
        {
            object instructor = 0;
            foreach(object teacher in Teachers)
            {
                if (teacher.teachesResearch(path))
                {
                    instructor = teacher;
                }
            }
            ExpectTrue(objectp(instructor), "Instructor for " + path);
            if (instructor)
            {
                learned = User.learnResearchFrom(instructor, path);
            }
        }
        else
        {
            learned = User.initiateResearch(path);
        }
        ExpectTrue(learned, path + ": " + User.caughtMessage());
        ResearchSpent += before - User.researchPoints();
    }
}

/////////////////////////////////////////////////////////////////////////////
void PrepareMonkTrial(string trial, string school)
{
    object lesson = getService("research")->researchObject(trial);
    mapping prerequisites = lesson.getPrerequisites();
    mapping practice = prerequisites["specialist practice"];
    if (mappingp(practice))
    {
        mapping *routes = filter(practice["criteria"],
            (: strstr($1["research"], $2) == 0 :),
            "/guilds/monk/" + school + "/");
        ExpectEq(1, sizeof(routes), school + " has an Adept route");
        if (sizeof(routes) == 1)
        {
            LearnLesson(routes[0]["research"]);
            RecordPractice(([
                "criteria":routes[0],
                "value":practice["value"]
            ]));
        }
    }
    else
    {
        mapping *routes = filter(prerequisites["specialist mastery"]
            ["prerequisites"],
            (: strstr($1["qualifying practice"]["criteria"]["research"],
                $2) == 0 :), "/guilds/monk/" + school + "/");
        ExpectEq(1, sizeof(routes), school + " has an upper trial route");
        if (sizeof(routes) == 1)
        {
            foreach(string path, mapping requirement in routes[0])
            {
                if (requirement["type"] == "research")
                {
                    LearnLesson(path);
                }
            }
            RecordPractice(routes[0]["qualifying practice"]);
        }
    }
    LearnLesson(trial);
}

/////////////////////////////////////////////////////////////////////////////
void AdvanceBuild(string guild, string school, int level)
{
    mapping promotions = ([
        10:"disciplined-breath",
        20:"students-awareness",
        30:"disciples-insight",
        40:"adepts-focus",
        55:"inner-discipline",
        70:"mastery-of-fundamentals"
    ]);
    mapping trials = ([
        30:"adepts-trial",
        40:"senior-disciples-trial",
        55:"master-candidates-trial",
        70:"masters-trial"
    ]);
    if (guild == "monk")
    {
        LearnLesson("/guilds/monk/discipline/initiates-discipline.c");
    }
    for (int current = 2; current <= level; current++)
    {
        User.addExperience(User.experienceToNextLevel(guild), guild);
        ExpectTrue(User.advanceLevel(guild));
        if (guild == "monk")
        {
            if (current == 2 || current == 3)
            {
                LearnLesson("/guilds/monk/discipline/" +
                    (current == 2 ? "steady-practice" :
                        "teachers-recognition") + ".c");
            }
            if (member(promotions, current))
            {
                LearnLesson("/guilds/monk/discipline/" +
                    promotions[current] + ".c");
                if (member(trials, current))
                {
                    PrepareMonkTrial("/guilds/monk/discipline/" +
                        trials[current] + ".c", school);
                }
                ExpectTrue(User.advanceRank("monk"));
            }
        }
    }
    ExpectEq(level, User.guildLevel(guild));
}

/////////////////////////////////////////////////////////////////////////////
void TrainBuild(string primary)
{
    string attribute = primary == "bow" ? "dexterity" : "strength";
    int points = User.attributePoints();
    if (points)
    {
        ExpectTrue(User.spendAttributePoints(attribute, points));
    }
    foreach(string skill in ({ primary, "anatomy and physiology",
        "perception", "physics", "tactics", "parry", "dodge", "acrobatics",
        "dancing", "mathematics", "meditation", "concentration" }))
    {
        int cost = User.advanceSkillCost(skill, 1);
        int capacity = User.attributeValue(getService("skills")->
            attributeForSkill(skill)) + 10 - User.getSkill(skill, 1);
        int amount = min(({ capacity, User.AvailableSkillPoints() / cost }));
        if (amount > 0)
        {
            ExpectTrue(User.advanceSkill(skill, amount), skill);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void PrepareBuild(string guild, string school, string blueprint, int level)
{
    CleanUp();
    ResearchSpent = 0;
    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name(sprintf("martialcomparison%d", ++StudentNumber));
    User.Race("human");
    User.Str(10);
    User.Dex(10);
    User.Int(10);
    User.Wis(10);
    User.Con(10);
    User.Chr(10);
    User.colorConfiguration("none");
    move_object(User, Room);
    ExpectTrue(User.joinGuild(guild));
    AdvanceBuild(guild, school, level);
    ExpectEq(5 * level, User.AvailableSkillPoints(),
        guild + " awards its authored skill-point budget once");
    ExpectEq(level * (guild == "fighter" ? 6 : guild == "monk" ? 4 : 5),
        getService("guilds")->guildObject(guild).queryBonus(
            "bonus hit points", level, User.guildRank(guild)),
        guild + " applies its authored hit-point progression once");
    Weapon = clone_object("/lib/items/weapon.c");
    Weapon.set("blueprint", blueprint);
    Weapon.set("name", "comparisonweapon");
    Weapon.set("craftsmanship", 50);
    move_object(Weapon, User);
    ExpectTrue(Weapon.equip("comparisonweapon"));
    TrainBuild(Weapon.query("weapon type"));
    Target = clone_object("/lib/tests/support/services/mockNPC.c");
    Target.Name("opponent");
    Target.Race("human");
    Target.Str(10);
    Target.Dex(10);
    Target.Int(10);
    Target.Wis(10);
    Target.Con(10);
    Target.effectiveLevel(level);
    Target.setMaxHitPoints(1000000);
    move_object(Target, Arena);
    if (blueprint == "long bow")
    {
        Arrows = clone_object("/lib/items/ammunition.c");
        Arrows.set("name", "comparisonquiver");
        Arrows.set("ammunition type", "arrow");
        Arrows.set("max capacity", 10000);
        Arrows.set("quantity", 10000);
        move_object(Arrows, User);
    }
}

/////////////////////////////////////////////////////////////////////////////
mapping LessonClosure(string path, mapping lessons)
{
    if (!User.isResearched(path) && !member(lessons, path))
    {
        object item = getService("research")->researchObject(path);
        lessons[path] = item;
        foreach(string prerequisite, mapping requirement in
            item.getPrerequisites())
        {
            if (requirement["type"] == "research")
            {
                lessons = LessonClosure(prerequisite, lessons);
            }
        }
    }
    return lessons;
}

/////////////////////////////////////////////////////////////////////////////
void LearnSchool(string treePath, string guild, int level)
{
    object tree = getService("research")->researchTree(treePath);
    object *items = m_indices(tree.getFlattenedResearchTree());
    string *paths = sort_array(map(items, (: program_name($1) :)), (: $1 > $2 :));
    foreach(string path in paths)
    {
        mapping requiredLessons = LessonClosure(path, ([]));
        int affordable = 1;
        int cost = 0;
        foreach(object item in m_values(requiredLessons))
        {
            foreach(mapping prerequisite in
                m_values(item.getPrerequisites()))
            {
                if (prerequisite["type"] == "level" &&
                    prerequisite["guild"] == guild)
                {
                    affordable &&= prerequisite["value"] <= level;
                }
            }
            affordable &&= member(({ "points", "granted", "tree root" }),
                item.query("research type")) >= 0;
            if (item.query("research type") == "points")
            {
                cost += item.query("research cost");
            }
        }
        if (affordable && cost <= User.researchPoints())
        {
            LearnLesson(path);
        }
    }
    ExpectTrue(User.researchPoints() >= 0);
}

/////////////////////////////////////////////////////////////////////////////
mapping *DamageAbilities(string *trees)
{
    mapping *ret = ({});
    foreach(string path in trees)
    {
        object tree = getService("research")->researchTree(path);
        foreach(object item in m_indices(tree.getFlattenedResearchTree()))
        {
            string research = program_name(item);
            if (User.isResearched(research) &&
                item.query("scope") == "targeted" &&
                pointerp(item.query("damage hit points")) &&
                item.canApplySpecification("", User))
            {
                int total = 0;
                for (int sample = 0; sample < 64; sample++)
                {
                    total += item.getEffectsToApply(User)["effects"]
                        ["damage hit points"];
                }
                string command = regreplace(item.query("command template"),
                    "##Target##", "opponent", 1);
                command = regreplace(command, "\\[|\\]", "", 1);
                ret += ({ ([
                    "path":research,
                    "item":item,
                    "damage":total / 64,
                    "command":command
                ]) });
            }
        }
    }
    return sort_array(ret, (: $1["damage"] < $2["damage"] :));
}

/////////////////////////////////////////////////////////////////////////////
mapping MeasureCombat(mapping *abilities)
{
    int total = 0;
    int burst = 0;
    int uses = 0;
    int stamina = 0;
    int mana = 0;
    int maxCooldown = 2;
    foreach(mapping ability in abilities)
    {
        maxCooldown = max(({ maxCooldown, ability["item"].query("cooldown") }));
    }
    for (int sample = 0; sample < 2; sample++)
    {
        User.stopFight(Target);
        Target.stopFight(User);
        for (int tick = 0; sample && tick <= maxCooldown / 2; tick++)
        {
            User.heart_beat();
            User.resetCatchList();
        }
        User.hitPoints(1000000);
        User.spellPoints(1000000);
        User.staminaPoints(1000000);
        Target.hitPoints(1000000);
        int before = Target.hitPoints();
        User.registerAttacker(Target);
        Target.registerAttacker(User);
        for (int round = 0; round < 30; round++)
        {
            int applied = 0;
            foreach(mapping ability in abilities)
            {
                if (!applied &&
                    !User.spellAction() &&
                    !User.blockedByCooldown(ability["path"]))
                {
                    mapping cost = ability["item"].getUsageCosts("", User);
                    if (User.staminaPoints() >= cost["stamina point cost"] &&
                        User.spellPoints() >= cost["spell point cost"])
                    {
                        int previousStamina = User.staminaPoints();
                        int previousMana = User.spellPoints();
                        applied = User.executeCommand(ability["command"]);
                        ExpectTrue(applied, ability["path"] + ": " +
                            User.caughtMessage());
                        if (applied)
                        {
                            uses++;
                            stamina += previousStamina - User.staminaPoints();
                            mana += previousMana - User.spellPoints();
                        }
                    }
                }
            }
            User.heart_beat();
            User.resetCatchList();
            if (round == 0)
            {
                burst += before - Target.hitPoints();
            }
        }
        total += before - Target.hitPoints();
    }
    User.stopFight(Target);
    Target.stopFight(User);
    return ([
        "damage":total / 2,
        "burst":burst / 2,
        "uses":uses,
        "stamina":stamina / 2,
        "mana":mana / 2
    ]);
}

/////////////////////////////////////////////////////////////////////////////
void CompareBuild(string guild, string school, string blueprint,
    string *trees, int level)
{
    PrepareBuild(guild, school, blueprint, level);
    foreach(string tree in trees)
    {
        LearnSchool(tree, guild, level);
    }
    int budget = ResearchSpent + User.researchPoints();
    if (guild == "monk")
    {
        ExpectEq(level + 5, budget);
    }
    ExpectTrue(ResearchSpent <= budget);
    move_object(User, Arena);
    mapping *abilities = DamageAbilities(trees);
    ExpectTrue(sizeof(abilities) > 0, guild + " has eligible attacks");
    mapping weapon = MeasureCombat(({}));
    ExpectTrue(weapon["damage"] > 0, guild + " has normal weapon damage");
    mapping rotation = MeasureCombat(abilities);
    ExpectTrue(rotation["damage"] > 0, guild + " has rotation damage");
    ExpectTrue(rotation["uses"] > 0, guild + " executes an attack");
    debug_message(sprintf("Monk martial comparison: %s/%s L%d: "
        "RP %d/%d; HP/SP/ST %d/%d/%d; weapon/rotation damage "
        "%d/%d per 60s; burst %d; active ST/SP %d/%d; uses %d/2\n",
        guild, school, level, ResearchSpent, budget, User.maxHitPoints(),
        User.maxSpellPoints(), User.maxStaminaPoints(), weapon["damage"],
        rotation["damage"], rotation["burst"], rotation["stamina"],
        rotation["mana"], rotation["uses"]), 0x5);
}
