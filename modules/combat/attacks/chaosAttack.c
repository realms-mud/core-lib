//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/combat/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        ::reset(arg);
        setDamageType("chaos");
        damagesEthereal();
        addHitDictionary(({
            "spin", "gesticulate","gyrate", "pirouette", "gesture", "flourish" }));

        addSimileDictionary(({
            "wildly", "ecstatically", "fiercely", "ferociously", "haphazardly",
            "ridiculously", "savagely", "abruptly", "uncontrollably", "recklessly",
            "violently", "theatrically", "uproariously", "fantastically",
            "amazingly", "astonishingly", "wonderously", "menacingly" }));

        addMissMessage("##AttackerName## ##Infinitive::trip## over an invisible "
            "dead turtle!");

        addHitMessage("##AttackerName## ##HitDictionary## ##SimileDictionary## and "
            "##TargetPossessive::Name## ego is deflated.",
            "< 10");

        addHitMessage("##AttackerName## ##HitDictionary## ##SimileDictionary## and "
            "suddenly ##Infinitive::obsolete## ##TargetName##!", "< 120");
    }
}
