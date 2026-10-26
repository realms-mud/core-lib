//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/support/guilds/monkTrialFixture.c";

string *Catalogs = ({ "unarmed", "katana", "bludgeon", "pure-chi",
    "mana-shield", "paired-swords", "odachi", "archery", "kama", "claw" });
object Room;
object User;
object Target;
object *Equipment = ({});
object *Teachers = ({});
int StudentNumber;
mapping Checked;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    load_object("/guilds/monk/monk.c");
    ignoreList += ({ "NewStudent", "EquipWeapon", "CheckPrerequisites",
        "TeachMonkTrialLesson", "CompleteMonkUpperTrial" });
    Room = clone_object("/lib/environment/environment.c");
    foreach(string name in ({ "lian", "ren", "sora", "iori" }))
    {
        object teacher = clone_object("/guilds/monk/teachers/" + name + ".c");
        Teachers += ({ teacher });
        move_object(teacher, Room);
    }
}

/////////////////////////////////////////////////////////////////////////////
void NewStudent()
{
    foreach(object item in Equipment)
    {
        destruct(item);
    }
    Equipment = ({});
    if (objectp(Target))
    {
        destruct(Target);
    }
    if (objectp(User))
    {
        destruct(User);
    }
    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name(sprintf("catalogprogression%d", ++StudentNumber));
    User.Race("human");
    User.Str(20);
    User.Dex(20);
    User.Int(20);
    User.Wis(20);
    User.Con(20);
    User.colorConfiguration("none");
    move_object(User, Room);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    int *usage = rusage();
    int before = usage[0] + usage[1];
    NewStudent();
    usage = rusage();
    ExpectTrue(usage[0] + usage[1] - before <= 200,
        "Reused-teacher student setup <= 200ms CPU");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    foreach(object item in Equipment)
    {
        destruct(item);
    }
    Equipment = ({});
    if (objectp(Target))
    {
        destruct(Target);
    }
    destruct(User);
}

/////////////////////////////////////////////////////////////////////////////
void EquipWeapon(string blueprint, int offhand)
{
    object weapon = clone_object("/lib/items/weapon.c");
    string name = offhand ? "companion" : "practiceweapon";
    weapon.set("blueprint", blueprint);
    weapon.set("name", name);
    Equipment += ({ weapon });
    move_object(weapon, User);
    ExpectTrue(weapon.equip(name + (offhand ? " offhand" : "")),
        "Equipping " + blueprint);
}

/////////////////////////////////////////////////////////////////////////////
void TearDown()
{
    foreach(object teacher in Teachers)
    {
        destruct(teacher);
    }
    destruct(Room);
}

/////////////////////////////////////////////////////////////////////////////
void CheckPrerequisites(string path, int level, string rank,
    string *ancestors)
{
    ExpectTrue(member(ancestors, path) < 0, path + " has no cycle");
    string key = sprintf("%s#%d#%s", path, level, rank);
    if (member(ancestors, path) < 0 && !member(Checked, key))
    {
        object item = getService("lessons")->lessonObject(path);
        foreach(string name, mapping requirement in item.getPrerequisites())
        {
            if (requirement["type"] == "level" &&
                requirement["guild"] == "monk")
            {
                ExpectTrue(requirement["value"] <= level,
                    path + " is reachable by level " + level);
            }
            else if (requirement["type"] == "guild rank" &&
                requirement["guild"] == "monk")
            {
                ExpectTrue(member(requirement["value"], rank) >= 0,
                    path + " permits " + rank);
            }
            else if (requirement["type"] == "research")
            {
                CheckPrerequisites(name, level, rank, ancestors + ({ path }));
            }
        }
        Checked[key] = 1;
    }
}

/////////////////////////////////////////////////////////////////////////////
void EveryCatalogHasFortyReachableLevelsAndTheGuildCoversEveryLevel()
{
    mapping allLevels = ([]);
    Checked = ([]);
    foreach(string catalog in Catalogs)
    {
        mapping levels = ([]);
        string *paths = getService("lessons")->lessonPaths(
            "/guilds/monk/" + catalog + ".c");
        ExpectEq(40, sizeof(paths), catalog);
        foreach(string path in paths)
        {
            object item = getService("lessons")->lessonObject(path);
            int level = item.getPrerequisites()["level"]["value"];
            ExpectTrue(level >= 1 && level <= 70, path);
            ExpectFalse(member(levels, level), path + " distinct level");
            levels[level] = 1;
            allLevels[level] = 1;
            string rank = level < 10 ? "initiate" :
                level < 20 ? "student" : level < 30 ? "disciple" :
                level < 40 ? "adept" : level < 55 ? "senior disciple" :
                level < 70 ? "master candidate" : "master";
            CheckPrerequisites(path, level, rank, ({}));
        }
        ExpectTrue(member(levels, 1), catalog + " opens at one");
        ExpectTrue(member(levels, 70), catalog + " reaches seventy");
        for (int level = 1; level < 70; level++)
        {
            ExpectTrue(member(levels, level) ||
                member(levels, level + 1), catalog + " has no long gap");
        }
    }
    for (int level = 1; level <= 70; level++)
    {
        ExpectTrue(member(allLevels, level),
            sprintf("Guild has a lesson at level %d", level));
    }
}

/////////////////////////////////////////////////////////////////////////////
void AllSpecialistPromotionRoutesAreReachableBeforePromotion()
{
    Checked = ([]);
    string *trials = ({ "senior-disciples-trial",
        "master-candidates-trial", "masters-trial" });
    int *levels = ({ 40, 55, 70 });
    string *ranks = ({ "adept", "senior disciple", "master candidate" });
    for (int index = 0; index < sizeof(trials); index++)
    {
        object trial = getService("lessons")->lessonObject(
            "/guilds/monk/discipline/" + trials[index] + ".c");
        foreach(mapping route in trial.getPrerequisites()
            ["specialist mastery"]["prerequisites"])
        {
            foreach(string path, mapping requirement in route)
            {
                if (requirement["type"] == "research")
                {
                    CheckPrerequisites(path, levels[index], ranks[index],
                        ({}));
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void InstantaneousFormulasHaveDistinctSkillsAttributesAndResearch()
{
    foreach(string catalog in Catalogs)
    {
        foreach(string path in getService("lessons")->lessonPaths(
            "/guilds/monk/" + catalog + ".c"))
        {
            object item = getService("lessons")->lessonObject(path);
            mixed modifiers = item.query("modifiers");
            if (pointerp(modifiers))
            {
                int shield = path ==
                    "/guilds/monk/mana-shield/mindful-ward.c";
                ExpectTrue(sizeof(modifiers) >= (shield ? 5 : 8),
                    path + " depth");
                mapping distinct = ([]);
                int skills = 0;
                int attributes = 0;
                int research = 0;
                foreach(mapping modifier in modifiers)
                {
                    string key = modifier["type"] + "#" + modifier["name"];
                    ExpectFalse(member(distinct, key), path + " " + key);
                    distinct[key] = 1;
                    skills += member(({ "skill", "highest skill" }),
                        modifier["type"]) >= 0;
                    attributes += modifier["type"] == "attribute";
                    research += modifier["type"] == "research";
                }
                if (shield)
                {
                    ExpectEq(sizeof(modifiers), research,
                        "mana shield improves through its focused tree");
                }
                else
                {
                    ExpectTrue(skills >= 2, path + " skill contributions");
                    ExpectTrue(attributes >= 2,
                        path + " attribute contributions");
                    ExpectTrue(research >= 1,
                        path + " research contributions");
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void EveryKnowledgeBonusHasAnExecutableReceivingModifier()
{
    foreach(string catalog in Catalogs)
    {
        mapping items = ([]);
        foreach(string path in getService("lessons")->lessonPaths(
            "/guilds/monk/" + catalog + ".c"))
        {
            object item = getService("lessons")->lessonObject(path);
            items[item.query("name")] = item;
        }
        foreach(string name, object knowledge in items)
        {
            if (knowledge.query("affected research type") == "bonus")
            {
                foreach(string target, int bonus in
                    knowledge.query("affected research"))
                {
                    object receiver = items[target];
                    ExpectTrue(objectp(receiver), name + " targets " + target);
                    if (receiver)
                    {
                        int found = 0;
                        foreach(mapping modifier in receiver.query("modifiers"))
                        {
                            if (modifier["type"] == "research" &&
                                modifier["research item"] ==
                                    program_name(knowledge) &&
                                modifier["formula"] == "additive")
                            {
                                ExpectEq(to_float(bonus),
                                    modifier["rate"] * modifier["base value"],
                                    name + " modifies " + target);
                                found++;
                            }
                        }
                        ExpectEq(1, found, name + " wired to " + target);
                    }
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void EveryEntryLessonIsLearnableAndExecutableAtOneWithNaturalPoints()
{
    mapping weapons = ([
        "katana":"katana",
        "bludgeon":"staff",
        "paired-swords":"katana",
        "odachi":"odachi",
        "archery":"long bow",
        "kama":"kama",
        "claw":"tiger claws"
    ]);
    foreach(string catalog in Catalogs)
    {
        NewStudent();
        ExpectTrue(User.joinGuild("monk"));
        ExpectTrue(User.initiateResearch(
            "/guilds/monk/discipline/disciplined-breath.c"));
        ExpectTrue(User.learnResearchFrom(Teachers[0],
            "/guilds/monk/discipline/initiates-discipline.c"));
        string entry = 0;
        foreach(string path in getService("lessons")->lessonPaths(
            "/guilds/monk/" + catalog + ".c"))
        {
            if (getService("lessons")->lessonObject(path).getPrerequisites()
                ["level"]["value"] == 1)
            {
                entry = path;
            }
        }
        ExpectTrue(stringp(entry), catalog);
        TeachMonkTrialLesson(User, Teachers, entry);
        ExpectTrue(User.isResearched(entry), catalog);
        ExpectEq(1, User.guildLevel("monk"));
        ExpectTrue(User.researchPoints() >= 0, catalog + " natural budget");
        if (member(weapons, catalog))
        {
            EquipWeapon(weapons[catalog], 0);
        }
        if (catalog == "paired-swords")
        {
            EquipWeapon("wakisashi", 1);
        }
        if (catalog == "archery")
        {
            object arrows = clone_object("/lib/items/ammunition.c");
            Equipment += ({ arrows });
            arrows.set("name", "practice quiver");
            arrows.set("ammunition type", "arrow");
            arrows.set("max capacity", 1);
            arrows.set("quantity", 1);
            move_object(arrows, User);
        }
        Target = clone_object("/lib/realizations/npc.c");
        Target.Name("opponent");
        Target.Race("human");
        Target.effectiveLevel(1);
        Target.setMaxHitPoints(10000);
        move_object(Target, Room);
        ExpectTrue(Target.registerAttacker(User));
        ExpectTrue(User.registerAttacker(Target));
        User.hitPoints(10000);
        User.staminaPoints(10000);
        User.spellPoints(10000);
        int health = Target.hitPoints();
        int stamina = User.staminaPoints();
        int mana = User.spellPoints();
        object item = getService("lessons")->lessonObject(entry);
        string command = regreplace(item.query("command template"),
            "##Target##", "opponent", 1);
        ExpectTrue(User.executeCommand(command), catalog + " level-one use");
        if (item.query("type") == "sustained")
        {
            ExpectTrue(User.sustainedResearchIsActive(entry), catalog);
        }
        else
        {
            ExpectTrue(Target.hitPoints() < health, catalog + " deals damage");
            ExpectEq(stamina - item.query("stamina point cost"),
                User.staminaPoints(), catalog + " stamina");
            ExpectEq(mana - item.query("spell point cost"),
                User.spellPoints(), catalog + " spell points");
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void AllFourHundredLessonsAreTaughtAtTheirAuthoredLevels()
{
    ExpectTrue(User.joinGuild("monk"));
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/disciplined-breath.c"));
    ExpectTrue(User.learnResearchFrom(Teachers[0],
        "/guilds/monk/discipline/initiates-discipline.c"));
    User.addResearchPoints(1000);
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
    mapping lessons = ([]);
    foreach(string catalog in Catalogs)
    {
        foreach(string path in getService("lessons")->lessonPaths(
            "/guilds/monk/" + catalog + ".c"))
        {
            lessons[path] = getService("lessons")->lessonObject(path)
                .getPrerequisites()["level"]["value"];
        }
    }
    mapping promotions = ([
        10:"disciplined-breath",
        20:"students-awareness",
        30:"disciples-insight",
        40:"adepts-focus",
        55:"inner-discipline",
        70:"mastery-of-fundamentals"
    ]);
    mapping trials = ([ 40:0, 55:1, 70:2 ]);
    for (int level = 1; level <= 70; level++)
    {
        if (level > 1)
        {
            User.addExperience(User.experienceToNextLevel("monk"), "monk");
            ExpectTrue(User.advanceLevel("monk"));
        }
        ExpectEq(level, User.guildLevel("monk"));
        if (level == 2)
        {
            ExpectTrue(User.learnResearchFrom(Teachers[0],
                "/guilds/monk/discipline/steady-practice.c"));
        }
        if (level == 3)
        {
            ExpectTrue(User.learnResearchFrom(Teachers[0],
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
                ExpectTrue(User.learnResearchFrom(Teachers[1],
                    "/guilds/monk/discipline/adepts-trial.c"));
            }
            if (member(trials, level))
            {
                CompleteMonkUpperTrial(User, Teachers[0], Teachers[1],
                    trials[level]);
            }
            ExpectTrue(User.advanceRank("monk"));
        }
        foreach(string path, int available in lessons)
        {
            if (available == level)
            {
                TeachMonkTrialLesson(User, Teachers, path);
            }
        }
    }
    ExpectEq("master", User.guildRank("monk"));
    ExpectEq(400, sizeof(lessons));
    foreach(string path in m_indices(lessons))
    {
        ExpectTrue(User.isResearched(path), path);
    }
}
