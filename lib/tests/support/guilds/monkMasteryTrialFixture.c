//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/tests/support/guilds/monk-trials.h"

object User;
object Room;
object Lian;
object Ren;
object Sora;
object Iori;
object Target;
object *Gear;
string *Trials = ({ "senior-disciples-trial", "master-candidates-trial",
    "masters-trial" });
string *Ranks = ({ "senior disciple", "master candidate", "master" });
mapping Basics = ([
    "unarmed":"measured-palm",
    "katana":"measured-cut",
    "bludgeon":"measured-impact",
    "pure-chi":"focused-pulse",
    "paired-swords":"linked-cut",
    "odachi":"committed-cut",
    "archery":"measured-draw",
    "kama":"measured-hook",
    "claw":"measured-rake"
]);

void Init()
{
    load_object("/guilds/monk/monk.c");
    ignoreList += ({ "TeachMonkTrialLesson", "CompleteMonkUpperTrial",
        "TrialPath", "Routes", "RouteFor", "AdvanceTo", "AddEvidence",
        "TeachRoute", "PrepareAt", "RecoverPractice", "EquipFor",
        "ExerciseAllRoutes" });
}

void Setup()
{
    Gear = ({});
    Room = clone_object("/lib/environment/environment.c");
    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name("mastery candidate");
    User.Race("human");
    User.Str(20);
    User.Int(20);
    User.Dex(20);
    User.Con(20);
    User.Wis(20);
    User.Chr(20);
    User.colorConfiguration("none");
    Lian = clone_object("/guilds/monk/teachers/lian.c");
    Ren = clone_object("/guilds/monk/teachers/ren.c");
    Sora = clone_object("/guilds/monk/teachers/sora.c");
    Iori = clone_object("/guilds/monk/teachers/iori.c");
    Target = clone_object("/lib/realizations/npc.c");
    Target.Name("opponent");
    Target.effectiveLevel(15);
    Target.Int(30);
    Target.Con(30);
    Target.setMaxHitPoints(100000);
    foreach(object actor in ({ User, Lian, Ren, Sora, Iori, Target }))
    {
        move_object(actor, Room);
    }
}

void CleanUp()
{
    foreach(object item in Gear)
    {
        if (objectp(item))
        {
            destruct(item);
        }
    }
    foreach(object actor in ({ Target, Iori, Sora, Ren, Lian, User, Room }))
    {
        destruct(actor);
    }
}

string TrialPath(int stage)
{
    return "/guilds/monk/discipline/" + Trials[stage] + ".c";
}

mapping *Routes(int stage)
{
    object trial = getService("research")->researchObject(TrialPath(stage));
    return trial.getPrerequisites()["specialist mastery"]["prerequisites"];
}

mapping RouteFor(int stage, string discipline, string family)
{
    mapping ret = 0;
    string specific = 0;
    if (discipline == "bludgeon" && stage != 1)
    {
        specific = stage == 0 ? ([
            "staff":"sweeping-arc",
            "mace":"compact-blow",
            "hammer":"falling-head"
        ])[family] : ([
            "staff":"pressing-shaft",
            "mace":"taxing-contact",
            "hammer":"burdening-blow"
        ])[family];
    }
    foreach(mapping route in Routes(stage))
    {
        string technique = route["qualifying practice"]["criteria"]["research"];
        if (strstr(technique, "/guilds/monk/" + discipline + "/") == 0 &&
            (!specific || technique == "/guilds/monk/bludgeon/" +
                specific + ".c"))
        {
            ret = route;
        }
    }
    ExpectTrue(mappingp(ret), discipline + " trial route");
    return ret;
}

void AdvanceTo(int level)
{
    int advancing = 1;
    while (advancing && User.guildLevel("monk") < level)
    {
        User.addExperience(User.experienceToNextLevel("monk"), "monk");
        advancing = User.advanceLevel("monk");
    }
    ExpectEq(level, User.guildLevel("monk"));
}

void AddEvidence(mapping route, int count, int qualifying, string event)
{
    mapping criteria = route["qualifying practice"]["criteria"];
    for (int use = 0; use < count; use++)
    {
        ExpectTrue(mappingp(User.recordObservation(([
            "type":event ? event : criteria["type"],
            "context":([
                "research":criteria["research"],
                "qualifying opponent":qualifying
            ])
        ]), 1)));
    }
}

void TeachRoute(mapping route)
{
    foreach(string path, mapping condition in route)
    {
        if (condition["type"] == "research")
        {
            TeachMonkTrialLesson(User, ({ Lian, Ren, Sora, Iori }), path);
        }
    }
}

void PrepareAt(int stage, string discipline, string family)
{
    ExpectTrue(User.joinGuild("monk"));
    User.addResearchPoints(1000);
    ExpectTrue(User.learnResearchFrom(Lian,
        "/guilds/monk/discipline/initiates-discipline.c"));
    string *foundations = ({ "disciplined-breath", "students-awareness",
        "disciples-insight", "adepts-focus", "inner-discipline",
        "mastery-of-fundamentals" });
    for (int index = 0; index <= stage + 3; index++)
    {
        AdvanceTo(5 * (index + 1));
        ExpectTrue(User.initiateResearch("/guilds/monk/discipline/" +
            foundations[index] + ".c"));
        if (index == 2)
        {
            string basic = "/guilds/monk/" + discipline + "/" +
                Basics[discipline] + ".c";
            TeachMonkTrialLesson(User, ({ Lian, Ren, Sora, Iori }), basic);
            AddEvidence(([ "qualifying practice":([
                "criteria":([
                    "type":discipline == "pure-chi" ?
                        "research.use" : "combat.kata",
                    "research":basic
                ])
            ]) ]), 10, 1, 0);
            ExpectTrue(User.learnResearchFrom(Ren,
                "/guilds/monk/discipline/adepts-trial.c"));
        }
        if (index < stage + 3)
        {
            if (index >= 3)
            {
                mapping route = RouteFor(index - 3, discipline, family);
                TeachRoute(route);
                AddEvidence(route, route["qualifying practice"]["value"],
                    1, 0);
                ExpectTrue(User.learnResearchFrom(Ren,
                    TrialPath(index - 3)));
            }
            ExpectTrue(User.advanceRank("monk"));
        }
        if (!index)
        {
            ExpectTrue(User.learnResearchFrom(Lian,
                "/guilds/monk/discipline/steady-practice.c"));
            ExpectTrue(User.learnResearchFrom(Lian,
                "/guilds/monk/discipline/teachers-recognition.c"));
        }
    }
    ExpectFalse(User.advanceRank("monk"));
}

void RecoverPractice()
{
    User.stopFight(Target);
    Target.stopFight(User);
    for (int tick = 0; tick < 20; tick++)
    {
        User.heart_beat();
    }
    User.hitPoints(100000);
    User.staminaPoints(100000);
    User.spellPoints(100000);
    Target.staminaPoints(100000);
    Target.spellPoints(100000);
}

void EquipFor(string technique)
{
    string discipline = regreplace(technique,
        "^/guilds/monk/([^/]+)/.*$", "\\1");
    string blueprint = ([
        "katana":"katana",
        "paired-swords":"katana",
        "odachi":"odachi",
        "archery":"long bow",
        "kama":"kama",
        "claw":"tiger claws"
    ])[discipline];
    if (discipline == "bludgeon")
    {
        blueprint = strstr(technique, "sweeping-arc") >= 0 ||
            strstr(technique, "pressing-shaft") >= 0 ? "quarterstaff" :
            strstr(technique, "falling-head") >= 0 ||
            strstr(technique, "burdening-blow") >= 0 ? "war hammer" : "mace";
    }
    if (blueprint)
    {
        object weapon = clone_object("/lib/items/weapon.c");
        weapon.set("blueprint", blueprint);
        weapon.set("name", "implement");
        move_object(weapon, User);
        Gear += ({ weapon });
        ExpectTrue(weapon.equip("implement"));
    }
    if (discipline == "paired-swords")
    {
        object companion = clone_object("/lib/items/weapon.c");
        companion.set("blueprint", "wakisashi");
        companion.set("name", "companion");
        move_object(companion, User);
        Gear += ({ companion });
        ExpectTrue(companion.equip("companion offhand"));
    }
    if (discipline == "archery")
    {
        object arrows = clone_object("/lib/items/ammunition.c");
        arrows.set("name", "trial quiver");
        arrows.set("ammunition type", "arrow");
        arrows.set("max capacity", 40);
        arrows.set("quantity", 40);
        move_object(arrows, User);
        Gear += ({ arrows });
    }
}

void ExerciseAllRoutes(int stage)
{
    mapping *routes = Routes(stage);
    ExpectEq(stage == 1 ? 9 : 11, sizeof(routes));
    for (int index = 0; index < sizeof(routes); index++)
    {
        if (index)
        {
            CleanUp();
            Setup();
        }
        mapping route = routes[index];
        mapping practice = route["qualifying practice"];
        string technique = practice["criteria"]["research"];
        string discipline = regreplace(technique,
            "^/guilds/monk/([^/]+)/.*$", "\\1");
        string family = strstr(technique, "sweeping-arc") >= 0 ||
            strstr(technique, "pressing-shaft") >= 0 ? "staff" :
            strstr(technique, "falling-head") >= 0 ||
            strstr(technique, "burdening-blow") >= 0 ? "hammer" : "mace";
        PrepareAt(stage, discipline, family);
        TeachRoute(route);
        foreach(string other, string basic in Basics)
        {
            if (other != discipline)
            {
                ExpectFalse(User.isResearched("/guilds/monk/" + other +
                    "/" + basic + ".c"), "No forced " + other + " study");
            }
        }
        ExpectEq(20 + 10 * stage, practice["value"]);
        AddEvidence(route, practice["value"] - 1, 1, 0);
        ExpectFalse(User.canResearch(TrialPath(stage)), technique);
        EquipFor(technique);
        RecoverPractice();
        ExpectTrue(Target.registerAttacker(User));
        ExpectTrue(User.registerAttacker(Target));
        object action = getService("research")->researchObject(technique);
        string command = regreplace(action.query("command template"),
            "##Target##", "opponent");
        ExpectTrue(User.executeCommand(command), technique);
        ExpectEq(practice["value"],
            User.countObservations(practice["criteria"]), technique);
        ExpectTrue(User.canResearch(TrialPath(stage)), technique);
        ExpectFalse(User.advanceRank("monk"));
        RecoverPractice();
        ExpectFalse(User.initiateResearch(TrialPath(stage)));
        ExpectFalse(User.learnResearchFrom(Lian, TrialPath(stage)));
        move_object(Ren, this_object());
        ExpectFalse(User.learnResearchFrom(Ren, TrialPath(stage)));
        move_object(Ren, Room);
        int points = User.researchPoints();
        int respect = Ren.relationshipValue(User, "respect");
        int stamina = User.maxStaminaPoints();
        int hp = User.maxHitPoints();
        int sp = User.maxSpellPoints();
        object trial = getService("research")->researchObject(TrialPath(stage));
        ExpectTrue(User.executeCommand("learn " +
            lower_case(trial.query("name")) + " from ren"));
        ExpectTrue(User.isResearched(TrialPath(stage)));
        ExpectEq(points, User.researchPoints());
        ExpectEq(respect + 2, Ren.relationshipValue(User, "respect"));
        ExpectEq(stamina, User.maxStaminaPoints());
        ExpectEq(hp, User.maxHitPoints());
        ExpectEq(sp, User.maxSpellPoints());
        ExpectFalse(User.learnResearchFrom(Ren, TrialPath(stage)));
        ExpectEq(respect + 2, Ren.relationshipValue(User, "respect"));
        ExpectTrue(User.executeCommand("advance with lian"));
        ExpectEq(Ranks[stage], User.guildRank("monk"));
        ExpectEq(points, User.researchPoints());
    }
}
