//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/combinedInstantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Waking Nightmare");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of weaving psionic attacks by combining mental focus, "
        "dream imagery, and projection methods into devastating assaults "
        "on the target's psyche.");

    addSpecification("scope", "targeted");
    addSpecification("research type", "tree root");
    addSpecification("maximum combination chain", 2);
    addSpecification("spell point cost", 35);
    addSpecification("stamina point cost", 10);

    addSpecification("combination rules", ([
        "must include any of": ({ 
            // Psionic Focus attacks (18 total)
            "/guilds/oneiromancer/psionic-focus/mind-spike.c",
            "/guilds/oneiromancer/psionic-focus/psychic-lash.c",
            "/guilds/oneiromancer/psionic-focus/thought-crush.c",
            "/guilds/oneiromancer/psionic-focus/neural-sever.c",
            "/guilds/oneiromancer/psionic-focus/ego-rend.c",
            "/guilds/oneiromancer/psionic-focus/dream-fang.c",
            "/guilds/oneiromancer/psionic-focus/memory-shatter.c",
            "/guilds/oneiromancer/psionic-focus/cognitive-fracture.c",
            "/guilds/oneiromancer/psionic-focus/will-breaker.c",
            "/guilds/oneiromancer/psionic-focus/sanity-erosion.c",
            "/guilds/oneiromancer/psionic-focus/perception-warp.c",
            "/guilds/oneiromancer/psionic-focus/existential-dread.c",
            "/guilds/oneiromancer/psionic-focus/nightmare-fist.c",
            "/guilds/oneiromancer/psionic-focus/psychic-scream.c",
            "/guilds/oneiromancer/psionic-focus/soul-flense.c",
            "/guilds/oneiromancer/psionic-focus/mind-annihilation.c",
            "/guilds/oneiromancer/psionic-focus/dream-eater.c",
            "/guilds/oneiromancer/psionic-focus/void-thought.c"
        }),
        "can include only one of": ({ 
            // Dream Imagery (18 total)
            "/guilds/oneiromancer/dream-imagery/falling-terror.c",
            "/guilds/oneiromancer/dream-imagery/grasping-tentacles.c",
            "/guilds/oneiromancer/dream-imagery/burning-alive.c",
            "/guilds/oneiromancer/dream-imagery/lightning-strike.c",
            "/guilds/oneiromancer/dream-imagery/dissolving-flesh.c",
            "/guilds/oneiromancer/dream-imagery/paralytic-dread.c",
            "/guilds/oneiromancer/dream-imagery/teeth-crumbling.c",
            "/guilds/oneiromancer/dream-imagery/buried-alive.c",
            "/guilds/oneiromancer/dream-imagery/exposed-judged.c",
            "/guilds/oneiromancer/dream-imagery/endless-void.c",
            "/guilds/oneiromancer/dream-imagery/inescapable-maze.c",
            "/guilds/oneiromancer/dream-imagery/drowning-depths.c",
            "/guilds/oneiromancer/dream-imagery/loved-ones-twisted.c",
            "/guilds/oneiromancer/dream-imagery/frozen-wasteland.c",
            "/guilds/oneiromancer/dream-imagery/forgotten-identity.c",
            "/guilds/oneiromancer/dream-imagery/death-of-self.c",
            "/guilds/oneiromancer/dream-imagery/unraveling-reality.c",
            "/guilds/oneiromancer/dream-imagery/nightmare-apocalypse.c"
        }),
        "can include any of": ({ 
            // Projection Methods - Delivery (10)
            "/guilds/oneiromancer/projection-methods/eye-contact.c",
            "/guilds/oneiromancer/projection-methods/whispered-word.c",
            "/guilds/oneiromancer/projection-methods/gestured-sending.c",
            "/guilds/oneiromancer/projection-methods/empathic-bridge.c",
            "/guilds/oneiromancer/projection-methods/memory-anchor.c",
            "/guilds/oneiromancer/projection-methods/dream-thread.c",
            "/guilds/oneiromancer/projection-methods/psychic-touch.c",
            "/guilds/oneiromancer/projection-methods/thoughtform-projection.c",
            "/guilds/oneiromancer/projection-methods/subliminal-insertion.c",
            "/guilds/oneiromancer/projection-methods/collective-resonance.c",
            // Projection Methods - Intensity (7)
            "/guilds/oneiromancer/projection-methods/focused-intent.c",
            "/guilds/oneiromancer/projection-methods/penetrating-thought.c",
            "/guilds/oneiromancer/projection-methods/amplified-sending.c",
            "/guilds/oneiromancer/projection-methods/resonant-frequency.c",
            "/guilds/oneiromancer/projection-methods/overwhelming-presence.c",
            "/guilds/oneiromancer/projection-methods/perfect-clarity.c",
            "/guilds/oneiromancer/projection-methods/absolute-conviction.c",
            // Projection Methods - Tactical (8)
            "/guilds/oneiromancer/projection-methods/subtle-approach.c",
            "/guilds/oneiromancer/projection-methods/misdirection.c",
            "/guilds/oneiromancer/projection-methods/rapid-sending.c",
            "/guilds/oneiromancer/projection-methods/efficient-channeling.c",
            "/guilds/oneiromancer/projection-methods/lingering-trauma.c",
            "/guilds/oneiromancer/projection-methods/cascading-horror.c",
            "/guilds/oneiromancer/projection-methods/defensive-feedback.c",
            "/guilds/oneiromancer/projection-methods/nightmare-echo.c"
        })
    ]));

    addSpecification("max combination chain modifier", ({ 
        ([
            "type": "research",
            "research item": 
                "/guilds/oneiromancer/psionic-combinations/triple-thread.c",
            "name": "Triple Thread",
            "formula": "additive",
            "base value": 1,
            "rate": 1.0
        ]), 
        ([
            "type": "research",
            "research item": 
                "/guilds/oneiromancer/psionic-combinations/quadruple-thread.c",
            "name": "Quadruple Thread",
            "formula": "additive",
            "base value": 1,
            "rate": 1.0
        ]), 
        ([
            "type": "research",
            "research item": 
                "/guilds/oneiromancer/psionic-combinations/quintuple-thread.c",
            "name": "Quintuple Thread",
            "formula": "additive",
            "base value": 1,
            "rate": 1.0
        ]),
        ([
            "type": "research",
            "research item": 
                "/guilds/oneiromancer/psionic-combinations/sextuple-thread.c",
            "name": "Sextuple Thread",
            "formula": "additive",
            "base value": 1,
            "rate": 1.0
        ]),
    }));

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item":
                "/guilds/oneiromancer/psionic-combinations/layered-assault.c",
            "name": "Layered Assault",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.05
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/oneiromancer/psionic-combinations/mental-momentum.c",
            "name": "Mental Momentum",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.05
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/oneiromancer/psionic-combinations/cascading-thoughts.c",
            "name": "Cascading Thoughts",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.05
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/oneiromancer/psionic-combinations/amplified-horror.c",
            "name": "Amplified Horror",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/oneiromancer/psionic-combinations/woven-terror.c",
            "name": "Woven Terror",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/oneiromancer/psionic-combinations/devastating-focus.c",
            "name": "Devastating Focus",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/oneiromancer/psionic-combinations/nightmare-mastery.c",
            "name": "Nightmare Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/oneiromancer/psionic-combinations/dream-lord.c",
            "name": "Dream Lord",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type":"skill",
            "name": "mind",
            "formula": "logarithmic",
            "base value": 5,
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "senses",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type":"attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]), 
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.03
        ]),
    }));

    addSpecification("cooldown", 60);
    addSpecification("cooldown modifiers", ([
        "/guilds/oneiromancer/psionic-combinations/swift-nightmare.c": 10,
        "/guilds/oneiromancer/psionic-combinations/efficient-weaving.c": 10,
        "/guilds/oneiromancer/psionic-combinations/relentless-horror.c": 15,
        "/guilds/oneiromancer/psionic-combinations/terror-weaver.c": 15,
    ]));

    addSpecification("event handler", "wakingNightmareEvent");
    addSpecification("command template", "waking nightmare ##Combinations## [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::fix## "
        "##InitiatorPossessive## gaze upon ##TargetName##, eyes burning with "
        "otherworldly intensity");
}
