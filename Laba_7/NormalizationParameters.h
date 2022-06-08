#ifndef NORMALIZATIONPARAMETERS_H
#define NORMALIZATIONPARAMETERS_H

class NormalizationParameters
{
public:
    float Min;

    float Max;

    float DxStep;

    float DyStep;

    float XShift;

    float YShift;

    float Scale = 0.2;

    float degree;
};

#endif // NORMALIZATIONPARAMETERS_H
