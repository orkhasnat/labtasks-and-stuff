#include "Sequencer.h"

#include <stdexcept>

Sequencer::Sequencer(IActor& sequencingActor)
	: m_Actor{ sequencingActor }, m_CurrentFrame{ 0.0 }
{
}

Translation2D Sequencer::GetTranslationAt(double frame) const
{
#if USE_TEMPLATE_FOR_KEYS
	return GetTransformationAt(m_TranslationKeys, frame);
#else
	auto& [leftEntry, rightEntry] = GetRangeFromFrame(m_TranslationKeys, frame);
	if (DoubleEq(leftEntry.Frame, rightEntry.Frame))
	{
		return leftEntry.Transform;
	}
	else
	{
		double ratio = (frame - leftEntry.Frame) / (rightEntry.Frame - leftEntry.Frame);
		return Lerp(leftEntry.Transform, rightEntry.Transform, ratio);
	}
#endif
}

Rotation2D Sequencer::GetRotationAt(double frame) const
{
#if USE_TEMPLATE_FOR_KEYS
	return GetTransformationAt(m_RotationKeys, frame);
#else
	auto& [leftEntry, rightEntry] = GetRangeFromFrame(m_RotationKeys, frame);
	if (DoubleEq(leftEntry.Frame, rightEntry.Frame))
	{
		return leftEntry.Transform;
	}
	else
	{
		double ratio = (frame - leftEntry.Frame) / (rightEntry.Frame - leftEntry.Frame);
		return Lerp(leftEntry.Transform, rightEntry.Transform, ratio);
	}
#endif
}

Scale2D Sequencer::GetScaleAt(double frame) const
{
#if USE_TEMPLATE_FOR_KEYS
	return GetTransformationAt(m_ScaleKeys, frame);
#else
	auto& [leftEntry, rightEntry] = GetRangeFromFrame(m_ScaleKeys, frame);
	if (DoubleEq(leftEntry.Frame, rightEntry.Frame))
	{
		return leftEntry.Transform;
	}
	else
	{
		double ratio = (frame - leftEntry.Frame) / (rightEntry.Frame - leftEntry.Frame);
		return Lerp(leftEntry.Transform, rightEntry.Transform, ratio);
	}
#endif
}

Color Sequencer::GetColorAt(double frame) const
{
#if USE_TEMPLATE_FOR_KEYS
	return GetTransformationAt(m_ColorKeys, frame);
#else
	auto& [leftEntry, rightEntry] = GetRangeFromFrame(m_ColorKeys, frame);
	if (DoubleEq(leftEntry.Frame, rightEntry.Frame))
	{
		return leftEntry.Transform;
	}
	else
	{
		double ratio = (frame - leftEntry.Frame) / (rightEntry.Frame - leftEntry.Frame);
		return Lerp(leftEntry.Transform, rightEntry.Transform, ratio);
	}
#endif
}

void Sequencer::SortTranslationKeys()
{
	std::sort(m_TranslationKeys.begin(), m_TranslationKeys.end());
}

void Sequencer::SortRotationKeys()
{
	std::sort(m_RotationKeys.begin(), m_RotationKeys.end());
}

void Sequencer::SortScaleKeys()
{
	std::sort(m_ScaleKeys.begin(), m_ScaleKeys.end());
}

void Sequencer::SortColorKeys()
{
	std::sort(m_ColorKeys.begin(), m_ColorKeys.end());
}

void Sequencer::SortAllKeys()
{
	SortTranslationKeys();
	SortRotationKeys();
	SortScaleKeys();
	SortColorKeys();
}

void Sequencer::SetTranslationKey(double frame, const Translation2D& translation)
{
	m_TranslationKeys.push_back({ frame, translation });
}

void Sequencer::SetRotationKey(double frame, const Rotation2D& rotation)
{
	m_RotationKeys.push_back({ frame, rotation });
}

void Sequencer::SetScaleKey(double frame, const Scale2D& scale)
{
	m_ScaleKeys.push_back({ frame, scale });
}

void Sequencer::SetColorKey(double frame, const Color& color)
{
	m_ColorKeys.push_back({ frame, color });
}

void Sequencer::SetCurrentFrame(double frame)
{
	if (m_TranslationKeys.empty() || m_ScaleKeys.empty() ||
		m_RotationKeys.empty() || m_ColorKeys.empty())
	{
		throw std::length_error("Must have at least one keyframe for each type");
	}
	m_Actor.BaseTranslation() = GetTranslationAt(frame);
	m_Actor.BaseRotation() = GetRotationAt(frame);
	m_Actor.BaseScale() = GetScaleAt(frame);
	m_Actor.BaseColor() = GetColorAt(frame);
}

void Sequencer::Draw(Image& image) const
{
	m_Actor.Draw(image);
}
