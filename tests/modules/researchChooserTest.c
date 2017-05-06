//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

#define Block 1
#define Describe 2
#define Success 3

object User;
object ResearchChooser;
mapping Data;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    ResearchChooser = clone_object("/lib/modules/guilds/researchChooser.c");

    User = clone_object("/lib/tests/support/services/researchWithMockServices");
    User->Name("Bob");
    User->Str(20);
    User->Dex(20);
    User->Con(20);
    User->Int(20);
    User->Wis(20);
    User->ToggleMockGuilds();
    User->SetGuild("mage");
    User->SetLevel(10);
    User->addSkillPoints(100);
    User->advanceSkill("long sword", 10);

    mapping researchChoice = ([
        "type": "research choice",
        "name": "test choice",
        "description": "Test description",
        "apply": "at level 5",
        "research objects": ({ "lib/tests/support/research/testLimitedActiveResearchItem.c",
            "lib/tests/support/research/testGrantedResearchItem.c" })
    ]);
    User->addResearchChoice(researchChoice);
    User->registerEvent(ResearchChooser);

    // Having these out-of-order tests selection sorting
    Data = ([
        "2":([
            "choice":"test choice",
            "type": "research object",
            "name" : "second option",
            "description" : "second description",
            "key" : "lib/tests/support/research/testLimitedActiveResearchItem.c"
        ]),
        "1": ([
            "choice": "test choice",
            "type": "research object",
            "name" : "first option",
            "description" : "first description",
            "key" : "lib/tests/support/research/testGrantedResearchItem.c"
        ])
    ]);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(User);
    destruct(ResearchChooser);
}

/////////////////////////////////////////////////////////////////////////////
void OnResearchChoiceAvailableDoesNothingWhenResearchTitleNotSet()
{
    ResearchChooser->onResearchChoiceAvailable(User, Data);
    ExpectEq("", ResearchChooser->displayMessage());
}

/////////////////////////////////////////////////////////////////////////////
void OnResearchChoiceAvailableDoesNothingWhenResearchTitleDoesNotMatchData()
{
    ResearchChooser->setResearchTitle("blah");
    ResearchChooser->onResearchChoiceAvailable(User, Data);
    ExpectEq("", ResearchChooser->displayMessage());
}

/////////////////////////////////////////////////////////////////////////////
void OnResearchChoiceAvailableSetsUpObjectWhenResearchTitleSet()
{
    ResearchChooser->setResearchTitle("test choice");
    ResearchChooser->onResearchChoiceAvailable(User, Data);
    ExpectEq("[0;36mA new research choice is available: [0m[0;37;1mtest choice[0m\n\t[[0;31m1[0m] - [0;32mfirst option[0m\n\t[[0;31m2[0m] - [0;32msecond option[0m\n[0;32;1mYou must select a number from 1 to 2.\n[0m[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m",
        ResearchChooser->displayMessage());
}

/////////////////////////////////////////////////////////////////////////////
void OnResearchChoiceAvailableUnregistersEventWhenResearchTitleSet()
{
    ResearchChooser->setResearchTitle("test choice");

    ExpectFalse(User->registerEvent(ResearchChooser), "re-registering an event handler fails");
    ResearchChooser->onResearchChoiceAvailable(User, Data);
    ExpectTrue(User->registerEvent(ResearchChooser), "Since the event handler is not registered, re-registering succeeds");
}

/////////////////////////////////////////////////////////////////////////////
void ApplyResearchChoiceReturnsZeroWhenChooserNotSetUp()
{
    ExpectEq(0, ResearchChooser->applyResearchChoice("1"));
}

/////////////////////////////////////////////////////////////////////////////
void ApplyResearchChoiceReturnsBlockWhenChooserSetUpAndAnythingButSelectionAttempted()
{
    ResearchChooser->setResearchTitle("test choice");
    ResearchChooser->onResearchChoiceAvailable(User, Data);
    ExpectEq(Block, ResearchChooser->applyResearchChoice("n"));
}

/////////////////////////////////////////////////////////////////////////////
void ApplyResearchChoiceReturnsDescribeWhenChooserSetUpAndDescriptionRequestedForValidChoice()
{
    ResearchChooser->setResearchTitle("test choice");
    ResearchChooser->onResearchChoiceAvailable(User, Data);
    ExpectEq(Describe, ResearchChooser->applyResearchChoice("describe 1"));
}

/////////////////////////////////////////////////////////////////////////////
void ApplyResearchChoiceReturnsBlockWhenChooserSetUpAndDescriptionRequestedForInvalidChoice()
{
    ResearchChooser->setResearchTitle("test choice");
    ResearchChooser->onResearchChoiceAvailable(User, Data);
    ExpectEq(Block, ResearchChooser->applyResearchChoice("describe frank"));
}

/////////////////////////////////////////////////////////////////////////////
void ApplyResearchChoiceReturnsSuccessWhenChooserSetUpAndOptionSelected()
{
    ResearchChooser->setResearchTitle("test choice");
    ResearchChooser->onResearchChoiceAvailable(User, Data);
    ExpectEq(Success, ResearchChooser->applyResearchChoice("1"));
    ExpectTrue(User->isResearched("lib/tests/support/research/testGrantedResearchItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUpDeletesResearchChooser()
{
    ExpectTrue(objectp(ResearchChooser));
    ResearchChooser->cleanUp();
    ExpectFalse(objectp(ResearchChooser));
}

/////////////////////////////////////////////////////////////////////////////
void OnResearchChoiceAvailableSilentlySelectsOptionIfOnlyOneObjectAvailable()
{
    m_delete(Data, "2");
    ResearchChooser->setResearchTitle("test choice");
    ResearchChooser->onResearchChoiceAvailable(User, Data);
    ExpectTrue(User->isResearched("lib/tests/support/research/testGrantedResearchItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void OnResearchChoiceAvailableSilentlySelectsOptionIfOnlyOneTreeAvailable()
{
    Data = ([
        "1": ([
            "choice": "test choice",
            "type": "research tree",
            "name" : "first option",
            "description" : "first description",
            "key" : "lib/tests/support/guilds/testGuildResearchTree.c"
        ])
    ]);
    ResearchChooser->setResearchTitle("test choice");
    ExpectFalse(User->isResearched("lib/tests/support/guilds/testGuildTreeRoot.c"));
    ResearchChooser->onResearchChoiceAvailable(User, Data);
    ExpectTrue(User->isResearched("lib/tests/support/guilds/testGuildTreeRoot.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ApplyResearchChoiceReturnsSuccessWhenPathSelected()
{
     Data = ([
        "1": ([
            "choice": "test choice",
            "type": "research tree",
            "name" : "first option",
            "description" : "first description",
            "key" : "lib/tests/support/guilds/testGuildResearchTree.c"
        ]),
        "2": ([
            "choice": "test choice",
            "type": "research tree",
            "name" : "second option",
            "description" : "second description",
            "key" : "lib/tests/support/research/testSecondResearchTree.c"
        ])
    ]);
    
    ResearchChooser->setResearchTitle("test choice");
    ResearchChooser->onResearchChoiceAvailable(User, Data);
    ExpectFalse(User->isResearched("lib/tests/support/guilds/testGuildTreeRoot.c"));
    ExpectFalse(member(User->availableResearchTrees(), "lib/tests/support/research/testSecondResearchTree.c") > -1);
    ExpectEq(Success, ResearchChooser->applyResearchChoice("2"));
    ExpectTrue(User->isResearched("lib/tests/support/guilds/testGuildTreeRoot.c"));
    ExpectTrue(member(User->availableResearchTrees(), "lib/tests/support/research/testSecondResearchTree.c") > -1);
}
