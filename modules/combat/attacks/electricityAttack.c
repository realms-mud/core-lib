inherit "/lib/modules/combat/attacks/baseAttack.c";

public void init()
{
    ::init();
    setDamageType("electricity");
    addHitDictionary(({
        "shock", "singe", "fry", "zap", "blast", "zing", "jolt",
        "zap" }));

    addSimileDictionary(({
        "through ##TargetPossessive::Name## ##BodyPart##", "leaving a scent of ozone",
        "with a sickening crackle" }));
        
    addMissMessage("##AttackerName## ##Infinitive::look## quite "
        "surprised as ##AttackerSubjective## ##Infinitive::shock## "
        "##AttackerReflexive## with a bolt of electricity.");

    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary##.", "1-50");
    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName##, "
        "scorching ##TargetPossessive## ##BodyPart##.", "51-90");
}



