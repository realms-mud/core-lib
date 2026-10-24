//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

string *Trees = ({
    "discipline",
    "unarmed",
    "katana",
    "bludgeon",
    "pure-chi",
    "mana-shield",
    "paired-swords",
    "odachi",
    "archery",
    "kama",
    "claw"
});
mapping Seen;
mapping Checked;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "CheckBranch", "CheckDependencies" });
}

/////////////////////////////////////////////////////////////////////////////
void CheckBranch(mapping branch, object tree)
{
    ExpectTrue(sizeof(branch) <= 4, tree.Name() + " branch width");
    foreach(object item, mixed children in branch)
    {
        string path = program_name(item);
        ExpectFalse(member(Seen, path), path + " displayed once");
        Seen[path] = 1;
        string *parents = tree.getParents(path);
        if (path != tree.TreeRoot())
        {
            ExpectEq(1, sizeof(parents), path + " display parent count");
            mapping requirements = item.getPrerequisites();
            ExpectTrue(member(requirements, parents[0]),
                path + " explicitly requires display parent");
            ExpectEq("research", requirements[parents[0]]["type"], path);
        }
        if (mappingp(children))
        {
            CheckBranch(children, tree);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void CheckDependencies(string path, string *ancestors)
{
    ExpectFalse(member(ancestors, path) >= 0, path + " no cycles");
    if (member(ancestors, path) < 0 && !member(Checked, path))
    {
        object item = getService("research")->researchObject(path);
        foreach(string prerequisite, mapping requirement in
            item.getPrerequisites())
        {
            if (requirement["type"] == "research")
            {
                CheckDependencies(prerequisite, ancestors + ({ path }));
            }
        }
        Checked[path] = 1;
    }
}

/////////////////////////////////////////////////////////////////////////////
void EveryLessonAppearsOnceUnderAnExplicitResearchPrerequisite()
{
    foreach(string name in Trees)
    {
        object tree = getService("research")->researchTree(
            "/guilds/monk/" + name + ".c");
        Seen = ([]);
        CheckBranch(tree.getResearchTree(), tree);
        ExpectEq(name == "discipline" ? 15 : 41, sizeof(Seen), name);
        ExpectEq(sizeof(tree.getFlattenedResearchTree()), sizeof(Seen), name);
    }
}

/////////////////////////////////////////////////////////////////////////////
void ActualResearchPrerequisitesHaveNoCrossTreeCycles()
{
    Checked = ([]);
    foreach(string name in Trees)
    {
        object tree = getService("research")->researchTree(
            "/guilds/monk/" + name + ".c");
        foreach(object item in m_indices(tree.getFlattenedResearchTree()))
        {
            CheckDependencies(program_name(item), ({}));
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void BludgeonMasteryRetainsBothTheoryAndDefensivePractice()
{
    string *theory = ({ "long-reach-geometry", "contact-geometry",
        "anvil-geometry" });
    string *practice = ({ "crossbar-defense", "haft-shelter",
        "braced-recovery" });
    string *mastery = ({ "staff-equilibrium", "mace-composure",
        "hammer-poise" });
    object tree = getService("research")->researchTree(
        "/guilds/monk/bludgeon.c");
    string base = "/guilds/monk/bludgeon/";
    for (int index = 0; index < sizeof(mastery); index++)
    {
        string path = base + mastery[index] + ".c";
        mapping requirements = tree.getResearchItem(path).getPrerequisites();
        ExpectEq("research", requirements[base + theory[index] + ".c"]
            ["type"], path);
        ExpectEq("research", requirements[base + practice[index] + ".c"]
            ["type"], path);
        ExpectEq(({ base + theory[index] + ".c" }), tree.getParents(path),
            path);
    }
}

/////////////////////////////////////////////////////////////////////////////
void BludgeonSpecialistsDoNotRequireAnotherWeaponSchool()
{
    string *schools = ({ "staff-fulcrum", "mace-head-alignment",
        "hammer-counterweight" });
    string *mastery = ({ "staff-equilibrium", "mace-composure",
        "hammer-poise" });
    for (int index = 0; index < sizeof(schools); index++)
    {
        string path = "/guilds/monk/bludgeon/" + mastery[index] + ".c";
        Checked = ([]);
        CheckDependencies(path, ({}));
        ExpectTrue(member(Checked,
            "/guilds/monk/bludgeon/" + schools[index] + ".c"), path);
        foreach(string other in schools - ({ schools[index] }))
        {
            ExpectFalse(member(Checked,
                "/guilds/monk/bludgeon/" + other + ".c"), path);
        }
    }
}
