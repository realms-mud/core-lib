//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

string ResearchItem = "/lib/tests/support/research/testActiveResearchItem.c";
object ResearchTree;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    ResearchTree = clone_object("/lib/modules/research/researchTree");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(ResearchTree);
}

/////////////////////////////////////////////////////////////////////////////
void ResearchTreesHavePrerequisites()
{
    ExpectTrue(member(inherit_list(ResearchTree), "/lib/core/prerequisites.c") > -1);
}

/////////////////////////////////////////////////////////////////////////////
void CanSetNameForResearchTree()
{
    ExpectTrue(ResearchTree->Name("research tree name"), "set the research name");
    ExpectEq("research tree name", ResearchTree->Name(), "query the research name");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetDescriptionForResearchTree()
{
    ExpectTrue(ResearchTree->Description("research tree description"), "set the research description");
    ExpectEq("research tree description", ResearchTree->Description(), "query the research description");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetSourceForResearchTree()
{
    ExpectTrue(ResearchTree->Source("research tree source"), "set the research source");
    ExpectEq("research tree source", ResearchTree->Source(), "query the research source");
}

/////////////////////////////////////////////////////////////////////////////
void AddingInvalidResearchElementThrowsError()
{
    string err = catch (ResearchTree->addResearchElement("/lib/blah"));
    string expectedError = "*ERROR - researchTree: The research element must exist in the location passed to this method and be a valid object before it can be added to any trees.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid names");
}

/////////////////////////////////////////////////////////////////////////////
void AddingDuplicateResearchElementThrowsError()
{
    ExpectTrue(ResearchTree->addResearchElement(ResearchItem), "add an element");
    string err = catch (ResearchTree->addResearchElement(ResearchItem));
    string expectedError = "*ERROR - researchTree: The research item /lib/tests/support/research/testActiveResearchItem.c is already a member of the research tree.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid names");
}

/////////////////////////////////////////////////////////////////////////////
void GetResearchTreeReturnsEmptyIfNoRootSet()
{
    ExpectEq(([]), ResearchTree->getResearchTree(), "query the tree");
    ExpectTrue(ResearchTree->addResearchElement(ResearchItem), "add an element");
    ExpectEq(([]), ResearchTree->getResearchTree(), "tree still empty");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetTreeRootForResearchTree()
{
    ExpectTrue(ResearchTree->addResearchElement(ResearchItem), "add an element");
    ExpectTrue(ResearchTree->TreeRoot(ResearchItem), "set the tree root");
    ExpectEq(ResearchItem, ResearchTree->TreeRoot(), "query the tree root");
    ExpectEq(([load_object(ResearchItem):0]), ResearchTree->getResearchTree(), "query the element");
}

/////////////////////////////////////////////////////////////////////////////
void SettingTreeRootWhenNodeNotInTreeReturnsFalse()
{
    ExpectFalse(ResearchTree->TreeRoot(ResearchItem), "set the tree root");
}

/////////////////////////////////////////////////////////////////////////////
void CannotSetAResearchItemAsItsOwnParent()
{
    ExpectTrue(ResearchTree->addResearchElement(ResearchItem), "add an element");
    ExpectTrue(ResearchTree->TreeRoot(ResearchItem), "set the tree root");
    string err = catch (ResearchTree->addChild(ResearchItem, ResearchItem));
    string expectedError = "*ERROR - researchTree: The child (/lib/tests/support/research/testActiveResearchItem.c) and parent (/lib/tests/support/research/testActiveResearchItem.c) must be unique valid researchItem objects.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchTreesCanBeConstructed()
{
    mapping expected = ([ 
        "/lib/tests/support/research/testActiveResearchItem.c": ([ 
            "/lib/modules/research/activeResearchItem.c": ([ 
                "/lib/modules/research/instantaneousRitualResearchItem.c": 0, 
                "/lib/modules/research/knowledgeResearchItem.c": ([ 
                    "/lib/modules/research/persistedRitualResearchItem.c": 0 
                ])
            ]),
            "/lib/modules/research/instantaneousActiveResearchItem.c": ([ 
                "/lib/modules/research/knowledgeResearchItem.c": ([ 
                    "/lib/modules/research/persistedRitualResearchItem.c": 0
                ]), 
                "/lib/modules/research/passiveResearchItem.c": ([ 
                    "/lib/modules/research/persistedActiveResearchItem.c": 0, 
                    "/lib/modules/research/persistedRitualResearchItem.c": 0
                ])
            ])
        ])
    ]);

    ExpectTrue(ResearchTree->addResearchElement(ResearchItem), "add testActiveResearchItem");
    ExpectTrue(ResearchTree->addResearchElement("/lib/modules/research/activeResearchItem.c"), "add activeResearchItem");
    ExpectTrue(ResearchTree->addResearchElement("/lib/modules/research/instantaneousActiveResearchItem.c"), "add instantaneousActiveResearchItem");
    ExpectTrue(ResearchTree->addResearchElement("/lib/modules/research/instantaneousRitualResearchItem.c"), "add instantaneousRitualResearchItem");
    ExpectTrue(ResearchTree->addResearchElement("/lib/modules/research/knowledgeResearchItem.c"), "add knowledgeResearchItem");
    ExpectTrue(ResearchTree->addResearchElement("/lib/modules/research/passiveResearchItem.c"), "add passiveResearchItem");
    ExpectTrue(ResearchTree->addResearchElement("/lib/modules/research/persistedActiveResearchItem.c"), "add persistedActiveResearchItem");
    ExpectTrue(ResearchTree->addResearchElement("/lib/modules/research/persistedRitualResearchItem.c"), "add persistedRitualResearchItem");
    ExpectTrue(ResearchTree->TreeRoot(ResearchItem), "set parent for instantaneousActiveResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/activeResearchItem.c", ResearchItem), "set parent for activeResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/instantaneousActiveResearchItem.c", ResearchItem), "set parent for instantaneousActiveResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/instantaneousRitualResearchItem.c", "/lib/modules/research/activeResearchItem.c"), "set parent for instantaneousRitualResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/knowledgeResearchItem.c", "/lib/modules/research/activeResearchItem.c"), "set parent for knowledgeResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/knowledgeResearchItem.c", "/lib/modules/research/instantaneousActiveResearchItem.c"), "set parent for knowledgeResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/passiveResearchItem.c", "/lib/modules/research/instantaneousActiveResearchItem.c"), "set parent for passiveResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/persistedActiveResearchItem.c", "/lib/modules/research/passiveResearchItem.c"), "set parent for persistedActiveResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/persistedRitualResearchItem.c", "/lib/modules/research/passiveResearchItem.c"), "set parent for persistedRitualResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/persistedRitualResearchItem.c", "/lib/modules/research/knowledgeResearchItem.c"), "set parent for persistedRitualResearchItem");
    ExpectEq(expected, ResearchTree->getResearchTree(), "tree with data");
}

/////////////////////////////////////////////////////////////////////////////
void GetFlattenedResearchTreeReturnsFlatList()
{
    mapping expected = ([
        "/lib/tests/support/research/testActiveResearchItem.c":([]),
        "/lib/modules/research/activeResearchItem.c":([]),
        "/lib/modules/research/instantaneousRitualResearchItem.c": ([]),
        "/lib/modules/research/knowledgeResearchItem.c": ([]),
        "/lib/modules/research/persistedActiveResearchItem.c": ([]),
        "/lib/modules/research/persistedRitualResearchItem.c": ([]),
        "/lib/modules/research/instantaneousActiveResearchItem.c": ([]),
        "/lib/modules/research/passiveResearchItem.c" : ([])
    ]);

    ExpectTrue(ResearchTree->addResearchElement(ResearchItem), "add testActiveResearchItem");
    ExpectTrue(ResearchTree->addResearchElement("/lib/modules/research/activeResearchItem.c"), "add activeResearchItem");
    ExpectTrue(ResearchTree->addResearchElement("/lib/modules/research/instantaneousActiveResearchItem.c"), "add instantaneousActiveResearchItem");
    ExpectTrue(ResearchTree->addResearchElement("/lib/modules/research/instantaneousRitualResearchItem.c"), "add instantaneousRitualResearchItem");
    ExpectTrue(ResearchTree->addResearchElement("/lib/modules/research/knowledgeResearchItem.c"), "add knowledgeResearchItem");
    ExpectTrue(ResearchTree->addResearchElement("/lib/modules/research/passiveResearchItem.c"), "add passiveResearchItem");
    ExpectTrue(ResearchTree->addResearchElement("/lib/modules/research/persistedActiveResearchItem.c"), "add persistedActiveResearchItem");
    ExpectTrue(ResearchTree->addResearchElement("/lib/modules/research/persistedRitualResearchItem.c"), "add persistedRitualResearchItem");
    ExpectTrue(ResearchTree->TreeRoot(ResearchItem), "set parent for instantaneousActiveResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/activeResearchItem.c", ResearchItem), "set parent for activeResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/instantaneousActiveResearchItem.c", ResearchItem), "set parent for instantaneousActiveResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/instantaneousRitualResearchItem.c", "/lib/modules/research/activeResearchItem.c"), "set parent for instantaneousRitualResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/knowledgeResearchItem.c", "/lib/modules/research/activeResearchItem.c"), "set parent for knowledgeResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/knowledgeResearchItem.c", "/lib/modules/research/instantaneousActiveResearchItem.c"), "set parent for knowledgeResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/passiveResearchItem.c", "/lib/modules/research/instantaneousActiveResearchItem.c"), "set parent for passiveResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/persistedActiveResearchItem.c", "/lib/modules/research/passiveResearchItem.c"), "set parent for persistedActiveResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/persistedRitualResearchItem.c", "/lib/modules/research/passiveResearchItem.c"), "set parent for persistedRitualResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/persistedRitualResearchItem.c", "/lib/modules/research/knowledgeResearchItem.c"), "set parent for persistedRitualResearchItem");
    ExpectEq(expected, ResearchTree->getFlattenedResearchTree(), "tree with data");
}

/////////////////////////////////////////////////////////////////////////////
void InfinitelyRecursingTreesWillThrowError()
{
    ExpectTrue(ResearchTree->addResearchElement(ResearchItem), "add testActiveResearchItem");
    ExpectTrue(ResearchTree->addResearchElement("/lib/modules/research/activeResearchItem.c"), "add activeResearchItem");
    ExpectTrue(ResearchTree->addResearchElement("/lib/modules/research/instantaneousActiveResearchItem.c"), "add instantaneousActiveResearchItem");
    ExpectTrue(ResearchTree->addResearchElement("/lib/modules/research/instantaneousRitualResearchItem.c"), "add instantaneousRitualResearchItem");
    ExpectTrue(ResearchTree->addResearchElement("/lib/modules/research/knowledgeResearchItem.c"), "add knowledgeResearchItem");
    ExpectTrue(ResearchTree->addResearchElement("/lib/modules/research/passiveResearchItem.c"), "add passiveResearchItem");
    ExpectTrue(ResearchTree->addResearchElement("/lib/modules/research/persistedActiveResearchItem.c"), "add persistedActiveResearchItem");
    ExpectTrue(ResearchTree->addResearchElement("/lib/modules/research/persistedRitualResearchItem.c"), "add persistedRitualResearchItem");
    ExpectTrue(ResearchTree->TreeRoot(ResearchItem), "set parent for instantaneousActiveResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/activeResearchItem.c", ResearchItem), "set parent for activeResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/instantaneousActiveResearchItem.c", ResearchItem), "set parent for instantaneousActiveResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/instantaneousRitualResearchItem.c", "/lib/modules/research/activeResearchItem.c"), "set parent for instantaneousRitualResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/knowledgeResearchItem.c", "/lib/modules/research/activeResearchItem.c"), "set parent for knowledgeResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/knowledgeResearchItem.c", "/lib/modules/research/instantaneousActiveResearchItem.c"), "set parent for knowledgeResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/passiveResearchItem.c", "/lib/modules/research/instantaneousActiveResearchItem.c"), "set parent for passiveResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/persistedActiveResearchItem.c", "/lib/modules/research/passiveResearchItem.c"), "set parent for persistedActiveResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/persistedRitualResearchItem.c", "/lib/modules/research/passiveResearchItem.c"), "set parent for persistedRitualResearchItem");
    ExpectTrue(ResearchTree->addChild("/lib/modules/research/persistedRitualResearchItem.c", "/lib/modules/research/knowledgeResearchItem.c"), "set parent for persistedRitualResearchItem");
    string err = catch (ResearchTree->addChild(ResearchItem, "/lib/modules/research/persistedRitualResearchItem.c"));
    string expectedError = "*ERROR - researchTree: The relationship for child (/lib/tests/support/research/testActiveResearchItem.c) and parent (/lib/modules/research/persistedRitualResearchItem.c) results in infinite recursion.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown");
}

/////////////////////////////////////////////////////////////////////////////
void PrerequisitesMetReturnsTrueWhenNoPrerequisites()
{
    object owner = clone_object("/lib/tests/support/services/combatWithMockServices");
    owner->ToggleMockResearch();

    ExpectTrue(owner->isResearched("duh"), "isResearched is working");
    ExpectTrue(ResearchTree->addResearchElement(ResearchItem), "add testActiveResearchItem");
    ExpectTrue(ResearchTree->TreeRoot(ResearchItem), "set root");
    ExpectTrue(ResearchTree->prerequisitesMetFor(ResearchItem, owner), "check prereqs");
}

/////////////////////////////////////////////////////////////////////////////
void PrerequisitesMetReturnsFalseWhenPrereqNotMet()
{
    object owner = clone_object("/lib/tests/support/services/combatWithMockServices");
    owner->ToggleMockResearch();
    ExpectTrue(ResearchTree->addResearchElement("/lib/tests/support/research/testResearchItemWithPrerequisite.c"), "add research item");
    ExpectTrue(ResearchTree->TreeRoot("/lib/tests/support/research/testResearchItemWithPrerequisite.c"), "set root");
    ExpectFalse(ResearchTree->prerequisitesMetFor("/lib/tests/support/research/testResearchItemWithPrerequisite.c", owner), "check prereqs");
}

/////////////////////////////////////////////////////////////////////////////
void PrerequisitesMetReturnsTrueWhenPrereqMet()
{
    object owner = clone_object("/lib/tests/support/services/combatWithMockServices");
    owner->Str(20);
    owner->addSkillPoints(100);
    owner->advanceSkill("long sword", 10);
    owner->ToggleMockResearch();
    ExpectTrue(ResearchTree->addResearchElement("/lib/tests/support/research/testResearchItemWithPrerequisite.c"), "add research item");
    ExpectTrue(ResearchTree->TreeRoot("/lib/tests/support/research/testResearchItemWithPrerequisite.c"), "set root");
    ExpectTrue(ResearchTree->prerequisitesMetFor("/lib/tests/support/research/testResearchItemWithPrerequisite.c", owner), "check prereqs");
}

/////////////////////////////////////////////////////////////////////////////
void GetFlattenedResearchTreeForOwnerReturnsFlatListWithDetails()
{
    mapping expected = ([
        "/lib/tests/support/research/testTreeRoot.c":(["researched":1]),
        "/lib/tests/support/research/itemWithModifier.c": (["can research":1]),
        "/lib/tests/support/research/testLimitedByIntoxResearchItem.c": (["researched":1]),
        "/lib/tests/support/research/mockResearchTimed.c": (["researching":1]),
        "/lib/tests/support/research/testResearchA.c" : (["can research": 1 ]),
        "/lib/tests/support/research/testResearchB.c" : (["can research":1]),
        "/lib/tests/support/research/testResearchC.c" : (["can research":1]),
        "/lib/tests/support/research/testResearchD.c" : ([]),
        "/lib/tests/support/research/testResearchE.c" : ([]),
        "/lib/tests/support/research/testResearchF.c" : ([]),
        "/lib/tests/support/research/testResearchG.c" : ([])
    ]);

    object owner = clone_object("/lib/realizations/player.c");
    owner->Name("Fred");
    owner->Str(20);
    owner->addSkillPoints(100);
    owner->advanceSkill("long sword", 10);

    ExpectTrue(owner->addResearchTree("/lib/tests/support/research/testDeepResearchTree.c"));
    ExpectTrue(owner->initiateResearch("/lib/tests/support/research/testLimitedByIntoxResearchItem.c"));
    ExpectTrue(owner->initiateResearch("/lib/tests/support/research/mockResearchTimed.c"));

    object tree = load_object("/lib/dictionaries/researchDictionary.c")->
        researchTree("/lib/tests/support/research/testDeepResearchTree.c");

    ExpectEq(expected, tree->getFlattenedResearchTree(owner), "tree with data");
}

