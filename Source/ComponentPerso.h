/*
  ==============================================================================

    ComponentPerso.h
    Created: 19 Apr 2025 9:17:10pm
    Author:  olivier

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class ComponentPerso  : public juce::Component
{
public:
    ComponentPerso();
    ~ComponentPerso() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void mouseDown(const juce::MouseEvent& event) override;
  

    void setSelected(bool selected);
    

    bool isComponentSelected() const; 

protected:
    bool isSelected = false; // État de sélection

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ComponentPerso)
};
