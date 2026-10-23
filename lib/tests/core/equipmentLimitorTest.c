//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Specification;
object User;
object Katana;
object Other;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Specification = clone_object(
        "/lib/tests/support/research/testSpecification.c");
    User = clone_object(
        "/lib/tests/support/services/combatWithMockServices.c");
    User.Name("bob");
    User.Str(20);
    User.Dex(20);
    User.Con(20);
    User.colorConfiguration("none");
    move_object(User, this_object());

    Katana = clone_object("/lib/items/weapon.c");
    Katana.set("blueprint", "katana");
    Katana.set("name", "katana");
    move_object(Katana, User);
    Other = clone_object("/lib/items/weapon.c");
    Other.set("blueprint", "bastard sword");
    Other.set("name", "other");
    move_object(Other, User);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Katana);
    destruct(Other);
    destruct(User);
    destruct(Specification);
}

/////////////////////////////////////////////////////////////////////////////
void ExactBlueprintRequiresEquippedItemNotJustMatchingSkill()
{
    ExpectTrue(Specification.addSpecification("limited by", ([
        "equipment":([ "blueprint":"katana" ])
    ])));
    ExpectFalse(Specification.canApplySpecification("test", User));
    ExpectEq(Katana.query("weapon type"), Other.query("weapon type"));
    ExpectTrue(Other.equip("other"));
    ExpectFalse(Specification.canApplySpecification("test", User));
    ExpectTrue(Other.unequip("other"));
    ExpectTrue(Katana.equip("katana"));
    ExpectTrue(Specification.canApplySpecification("test", User));
    ExpectTrue(Katana.unequip("katana"));
    ExpectFalse(Specification.canApplySpecification("test", User));
}

/////////////////////////////////////////////////////////////////////////////
void EmptySlotRulesValidateAllSlotsAndRejectMalformedValues()
{
    object service = getService("limitor");
    ExpectTrue(service.validLimitor(([
        "empty equipment slots":"wielded primary"
    ])));
    ExpectTrue(service.validLimitor(([
        "empty equipment slots":({ "wielded primary", "wielded offhand" })
    ])));
    ExpectFalse(service.validLimitor(([ "empty equipment slots":({}) ])));
    ExpectFalse(service.validLimitor(([ "empty equipment slots":"hands" ])));
    ExpectFalse(service.validLimitor(([
        "empty equipment slots":({ "wielded primary", 1 })
    ])));
}

/////////////////////////////////////////////////////////////////////////////
void EmptyWieldedSlotsIgnoreCarriedWeaponsAndWornGloves()
{
    Specification.addSpecification("limited by", ([
        "empty equipment slots":({ "wielded primary", "wielded offhand" })
    ]));
    ExpectTrue(Specification.canApplySpecification("test", User));
    ExpectTrue(Katana.equip("katana"));
    ExpectFalse(Specification.canApplySpecification("test", User));
    ExpectTrue(Katana.unequip("katana"));
    Other.set("equipment locations", OnehandedWeapon);
    ExpectTrue(Other.equip("other offhand"));
    ExpectFalse(Specification.canApplySpecification("test", User));
    ExpectTrue(Other.unequip("other"));
    object gloves = clone_object("/lib/items/armor.c");
    gloves.set("blueprint", "gloves");
    gloves.set("name", "gloves");
    move_object(gloves, User);
    ExpectTrue(gloves.equip("gloves"));
    ExpectTrue(Specification.canApplySpecification("test", User));
    ExpectSubStringMatch("slots are empty",
        Specification.displayLimiters("none", getService("configuration"), 1));
    ExpectTrue(gloves.unequip("gloves"));
    destruct(gloves);
}

/////////////////////////////////////////////////////////////////////////////
void IndependentInstancesOfTheSameBlueprintQualify()
{
    Other.set("blueprint", "katana");
    Specification.addSpecification("limited by", ([
        "equipment":([ "blueprint":"katana" ])
    ]));
    ExpectTrue(Katana.equip("katana"));
    ExpectTrue(Specification.canApplySpecification("test", User));
    ExpectTrue(Katana.unequip("katana"));
    ExpectTrue(Other.equip("other"));
    ExpectTrue(Specification.canApplySpecification("test", User));
}

/////////////////////////////////////////////////////////////////////////////
void LegacyTypeAndTypeAlternativesRetainBroadMatching()
{
    ExpectTrue(Other.equip("other"));
    Specification.addSpecification("limited by", ([
        "equipment":"hand and a half sword"
    ]));
    ExpectTrue(Specification.canApplySpecification("test", User));
    Specification.addSpecification("limited by", ([
        "equipment":({ "long sword", "hand and a half sword" })
    ]));
    ExpectTrue(Specification.canApplySpecification("test", User));
    Other.set("weapon type", "axe");
    ExpectFalse(Specification.canApplySpecification("test", User));
}

/////////////////////////////////////////////////////////////////////////////
void StructuredTypeRequiresNoSpecificBlueprint()
{
    Specification.addSpecification("limited by", ([
        "equipment":([ "type":"hand and a half sword" ])
    ]));
    ExpectTrue(Other.equip("other"));
    ExpectTrue(Specification.canApplySpecification("test", User));
    Other.set("weapon type", "axe");
    ExpectFalse(Specification.canApplySpecification("test", User));
}

/////////////////////////////////////////////////////////////////////////////
void CombinedBlueprintAndTypeMustMatchTheSameItem()
{
    Katana.set("weapon type", "axe");
    ExpectTrue(Katana.equip("katana"));
    ExpectTrue(Other.equip("other offhand"));
    Specification.addSpecification("limited by", ([
        "equipment":([
            "blueprint":"katana",
            "type":"hand and a half sword"
        ])
    ]));
    ExpectFalse(Specification.canApplySpecification("test", User));
    Katana.set("weapon type", "hand and a half sword");
    ExpectTrue(Specification.canApplySpecification("test", User));
}

/////////////////////////////////////////////////////////////////////////////
void SlotRequirementUsesActualEquipmentRegistry()
{
    Specification.addSpecification("limited by", ([
        "equipment":([
            "blueprint":"katana",
            "slot":"wielded primary"
        ])
    ]));
    ExpectTrue(Katana.equip("katana offhand"));
    ExpectFalse(Specification.canApplySpecification("test", User));
    ExpectTrue(Katana.unequip("katana"));
    ExpectTrue(Katana.equip("katana"));
    ExpectTrue(Specification.canApplySpecification("test", User));
}

/////////////////////////////////////////////////////////////////////////////
void PairedRequirementsAreAndNotOr()
{
    Specification.addSpecification("limited by", ([
        "equipment":({
            ([
                "blueprint":"katana",
                "slot":"wielded primary"
            ]),
            ([
                "blueprint":"bastard sword",
                "slot":"wielded offhand"
            ])
        })
    ]));
    ExpectTrue(Katana.equip("katana"));
    ExpectFalse(Specification.canApplySpecification("test", User));
    ExpectTrue(Other.equip("other offhand"));
    ExpectTrue(Specification.canApplySpecification("test", User));
    ExpectTrue(Other.unequip("other"));
    ExpectFalse(Specification.canApplySpecification("test", User));
}

/////////////////////////////////////////////////////////////////////////////
void FieldAlternativesRemainWithinOneRequirement()
{
    Specification.addSpecification("limited by", ([
        "equipment":([
            "blueprint":({ "katana", "bastard sword" }),
            "type":({ "long sword", "hand and a half sword" })
        ])
    ]));
    ExpectTrue(Other.equip("other"));
    ExpectTrue(Specification.canApplySpecification("test", User));
    Other.set("weapon type", "axe");
    ExpectFalse(Specification.canApplySpecification("test", User));
}

/////////////////////////////////////////////////////////////////////////////
void EquipmentBlueprintChangesAreNotCached()
{
    Specification.addSpecification("limited by", ([
        "equipment":([ "blueprint":"katana" ])
    ]));
    ExpectTrue(Katana.equip("katana"));
    ExpectTrue(Specification.canApplySpecification("test", User));
    Katana.set("blueprint", "bastard sword");
    ExpectFalse(Specification.canApplySpecification("test", User));
    Katana.set("blueprint", "katana");
    ExpectTrue(Specification.canApplySpecification("test", User));
}

/////////////////////////////////////////////////////////////////////////////
void LearningAndExecutionHaveSeparateEquipmentEligibility()
{
    string item =
        "/lib/tests/support/research/blueprintLimitedResearchItem.c";
    object learner = clone_object(
        "/lib/tests/support/services/mockPlayer.c");
    learner.Name("student");
    learner.Str(20);
    learner.Dex(20);
    learner.Con(20);
    move_object(learner, this_object());
    ExpectTrue(learner.canResearch(item));
    ExpectTrue(learner.initiateResearch(item));
    ExpectTrue(learner.isResearched(item));
    ExpectFalse(learner.researchCommand("practice blade"));
    move_object(Katana, learner);
    ExpectTrue(Katana.equip("katana"));
    ExpectTrue(learner.researchCommand("practice blade"));
    learner.heart_beat();
    ExpectTrue(Katana.unequip("katana"));
    ExpectFalse(learner.researchCommand("practice blade"));
    ExpectTrue(learner.isResearched(item));
    move_object(Katana, User);
    destruct(learner);
}

/////////////////////////////////////////////////////////////////////////////
void SkillThresholdAndBlueprintAreBothRequired()
{
    User.addSkillPoints(100);
    Specification.addSpecification("limited by", ([
        "equipment":([ "blueprint":"katana" ]),
        "skill":([ "hand and a half sword":5 ])
    ]));
    ExpectTrue(Katana.equip("katana"));
    ExpectFalse(Specification.canApplySpecification("test", User));
    ExpectTrue(User.advanceSkill("hand and a half sword", 5));
    ExpectTrue(Specification.canApplySpecification("test", User));
    ExpectTrue(Katana.unequip("katana"));
    ExpectTrue(Other.equip("other"));
    ExpectFalse(Specification.canApplySpecification("test", User));
}

/////////////////////////////////////////////////////////////////////////////
void BlueprintDoesNotFallBackToTheWeaponSkill()
{
    destruct(Other);
    Other = clone_object("/lib/items/weapon.c");
    Other.set("name", "other");
    Other.set("weapon type", "hand and a half sword");
    Other.set("equipment locations", OnehandedWeapon);
    move_object(Other, User);
    Specification.addSpecification("limited by", ([
        "equipment":([ "blueprint":"katana" ])
    ]));
    ExpectTrue(Other.equip("other"));
    ExpectFalse(Specification.canApplySpecification("test", User));
}

/////////////////////////////////////////////////////////////////////////////
void InvalidStructuredRequirementsAreRejectedAtAuthoring()
{
    mixed *invalid = ({
        ([]),
        ([ "slot":"wielded primary" ]),
        ([ "blueprint":"not a blueprint" ]),
        ([ "blueprint":({ "katana", "not a blueprint" }) ]),
        ([ "blueprint":({ }) ]),
        ([ "blueprint":({ "katana", 7 }) ]),
        ([ "blueprint":7 ]),
        ([ "type":"not a type" ]),
        ([ "type":({ "long sword", "not a type" }) ]),
        ([ "type":({ }) ]),
        ([ "blueprint":"katana", "slot":"backpack" ]),
        ([ "blueprint":"katana", "unknown":1 ]),
        ({ ([ "blueprint":"katana" ]), "long sword" }),
        ({ "long sword", ([ "blueprint":"katana" ]) }),
        ({ ([ "blueprint":"katana" ]), ([]) }),
        ({
            ([ "blueprint":"katana", "slot":"wielded primary" ]),
            ([ "blueprint":"bastard sword", "slot":"wielded primary" ])
        })
    });
    foreach(mixed requirement in invalid)
    {
        ExpectFalse(getService("limitor")->validLimitor(([
            "equipment":requirement
        ])));
        ExpectTrue(stringp(catch(Specification.addSpecification(
            "limited by", ([ "equipment":requirement ])); nolog)));
    }
}

/////////////////////////////////////////////////////////////////////////////
void DirectInventoryQueriesRejectInvalidRequirementsExplicitly()
{
    ExpectTrue(stringp(catch(User.usingEquipmentMatching(([
        "blueprint":"not a blueprint"
    ])); nolog)));
}

/////////////////////////////////////////////////////////////////////////////
void OverlappingBlueprintAlternativesInOneSlotRemainValid()
{
    ExpectTrue(Specification.addSpecification("limited by", ([
        "equipment":({
            ([
                "blueprint":({ "katana", "bastard sword" }),
                "slot":"wielded primary"
            ]),
            ([ "blueprint":"katana", "slot":"wielded primary" ])
        })
    ])));
    ExpectTrue(Katana.equip("katana"));
    ExpectTrue(Specification.canApplySpecification("test", User));
}

/////////////////////////////////////////////////////////////////////////////
void MissingInventoryCapabilityFailsClosed()
{
    object actor = clone_object("/lib/modules/settings.c");
    ExpectFalse(getService("limitor")->userFactorsMet(([
        "limited by":([
            "equipment":([ "blueprint":"katana" ])
        ])
    ]), actor));
    destruct(actor);
}

/////////////////////////////////////////////////////////////////////////////
void StructuredRequirementsHaveReadableDescriptionsAndDiagnostics()
{
    mapping requirement = ([
        "blueprint":"katana",
        "type":"hand and a half sword",
        "slot":"wielded primary"
    ]);
    Specification.addSpecification("limited by", ([
        "equipment":requirement
    ]));
    string description = "blueprint: katana; type: hand and a half sword; "
        "slot: wielded primary";
    ExpectEq("This is only applied when you're using: " + description +
        ".\n", Specification.displayLimiters("none",
            getService("configuration"), 1));
    object previousPlayer = this_player();
    set_this_player(User);
    User.resetCatchList();
    ExpectFalse(Specification.canApplySpecification("test", User, 0, 1));
    set_this_player(previousPlayer);
    ExpectEq("You must be using the proper equipment for that (" +
        description + ").\n", User.caughtMessage());
}
