//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Actor;
object Prerequisite;
object Specification;
object Limitor;
object Configuration;

void Setup()
{
    Actor = clone_object(
        "/lib/tests/support/research/observationRuleActor.c");
    Prerequisite = clone_object(
        "/lib/tests/support/research/prerequisiteItem.c");
    Specification = clone_object(
        "/lib/tests/support/research/testSpecification.c");
    Limitor = getService("limitor");
    Configuration = getService("configuration");
}

void CleanUp()
{
    destruct(Actor);
    destruct(Prerequisite);
    destruct(Specification);
}

void PrerequisiteRejectsMalformedObservationRules()
{
    foreach(mixed type in ({ 1, "", ({ "combat.kata" }) }))
    {
        ExpectFalse(Prerequisite.AddTestPrerequisite("kata", ([
            "type": "observation",
            "criteria": ([ "type": type ]),
            "value": 100
        ])));
    }
    foreach(mixed criteria in ({ 0, "combat.kata", ([]), ({ "kata" }) }))
    {
        ExpectFalse(Prerequisite.AddTestPrerequisite("kata", ([
            "type": "observation",
            "criteria": criteria,
            "value": 100
        ])));
    }
    foreach(mixed count in ({ 0, -1, "100", 1.5 }))
    {
        ExpectFalse(Prerequisite.AddTestPrerequisite("kata", ([
            "type": "observation",
            "criteria": ([ "type": "combat.kata" ]),
            "value": count
        ])));
    }
}

void PrerequisiteChecksThresholdAndForwardsCriteria()
{
    mapping criteria = ([
        "type": "combat.kata",
        "target race": "orc",
        "research": "/guilds/fighter/kata.c"
    ]);
    ExpectTrue(Prerequisite.AddTestPrerequisite("kata", ([
        "type": "observation",
        "criteria": criteria,
        "value": 100
    ])));
    Actor.setObservationCount(99);
    ExpectFalse(Prerequisite.checkPrerequisites(Actor));
    ExpectEq(criteria, Actor.queriedCriteria());
    Actor.setObservationCount(100);
    ExpectTrue(Prerequisite.checkPrerequisites(Actor));
    Actor.setObservationCount(101);
    ExpectTrue(Prerequisite.checkPrerequisites(Actor));
}

void PrerequisiteSupportsGroupedObservationRules()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("kata", ([
        "type": "observation",
        "criteria": ([ "type": "combat.kata" ]),
        "value": 1
    ]), "kata group"));
    ExpectFalse(Prerequisite.checkPrerequisites(Actor, "kata group"));
    Actor.setObservationCount(1);
    ExpectTrue(Prerequisite.checkPrerequisites(Actor, "kata group"));
}

void PrerequisiteFailsWithoutObservationQuerySupport()
{
    object unsupported = clone_object(
        "/lib/tests/support/services/combatWithMockServices.c");
    ExpectTrue(Prerequisite.AddTestPrerequisite("kata", ([
        "type": "observation",
        "criteria": ([ "type": "combat.kata" ]),
        "value": 1
    ])));
    ExpectFalse(Prerequisite.checkPrerequisites(unsupported));
    ExpectFalse(Prerequisite.checkPrerequisites(0));
    destruct(unsupported);
}

void PrerequisiteDisplaysObservationThreshold()
{
    ExpectTrue(Prerequisite.AddTestPrerequisite("kata", ([
        "type": "observation",
        "criteria": ([ "type": "combat.kata" ]),
        "value": 100
    ])));
    ExpectEq("Prerequisites:\n    Observation: "
        "Kata observation count of 100\n",
        Prerequisite.displayPrerequisites("none", Configuration));
}

void LimitorRejectsMalformedObservationRules()
{
    foreach(mixed observation in ({ 0, "combat.kata", ([]),
        ([ "type": "combat.kata" ]),
        ([ "minimum": 100 ]),
        ([ "type": "", "minimum": 100 ]),
        ([ "type": 1, "minimum": 100 ]) }))
    {
        ExpectFalse(Limitor.validLimitor(([ "observation": observation ])));
    }
    foreach(mixed count in ({ 0, -1, "100", 1.5 }))
    {
        ExpectFalse(Limitor.validLimitor(([
            "observation": ([ "type": "combat.kata", "minimum": count ])
        ])));
    }
}

void LimitorChecksThresholdAndRemovesOnlyMinimum()
{
    mapping criteria = ([
        "type": "combat.kata",
        "target race": "orc",
        "research": "/guilds/fighter/kata.c"
    ]);
    mapping observation = criteria + ([ "minimum": 100 ]);
    ExpectTrue(Specification.addSpecification("limited by", ([
        "observation": observation
    ])));
    Actor.setObservationCount(99);
    ExpectFalse(Specification.canApplySpecification("kata", Actor));
    ExpectEq(criteria, Actor.queriedCriteria());
    ExpectEq(100, observation["minimum"]);
    ExpectEq(observation,
        Specification.query("limited by")["observation"]);
    Actor.setObservationCount(100);
    ExpectTrue(Specification.canApplySpecification("kata", Actor));
    Actor.setObservationCount(101);
    ExpectTrue(Specification.canApplySpecification("kata", Actor));
}

void LimitorFailsWithoutObservationQuerySupport()
{
    object unsupported = clone_object(
        "/lib/tests/support/services/combatWithMockServices.c");
    ExpectTrue(Specification.addSpecification("limited by", ([
        "observation": ([ "type": "combat.kata", "minimum": 1 ])
    ])));
    ExpectFalse(Specification.canApplySpecification("kata", unsupported));
    destruct(unsupported);
}

void LimitorRejectsMalformedRulesAtRuntime()
{
    ExpectFalse(Limitor.userFactorsMet(([
        "limited by": ([
            "observation": ([ "type": "combat.kata", "minimum": 0 ])
        ])
    ]), Actor));
}

void LimitorDisplaysThresholdAndFilters()
{
    ExpectTrue(Specification.addSpecification("limited by", ([
        "observation": ([
            "type": "combat.kata",
            "target race": "orc",
            "research": "/guilds/fighter/kata.c",
            "minimum": 100
        ])
    ])));
    ExpectEq("This is only applied when you have at least 100 matching "
        "observations (combat.kata, research: \"/guilds/fighter/kata.c\", "
        "target race: \"orc\").\n",
        Specification.displayLimiters("none", Configuration, 1));
}

void LimitorProvidesVerboseFailureMessage()
{
    ExpectFalse(Limitor.userFactorsMet(([
        "limited by": ([
            "observation": ([ "type": "combat.kata", "minimum": 100 ])
        ])
    ]), Actor, 0, 1));
}