#pragma once

#include <vector>

#include "IActor.h"
#include "Util.h"

#define USE_TEMPLATE_FOR_KEYS 1

template<typename T>
struct FrameTransformPair
{
	double Frame;
	T Transform;

	inline FrameTransformPair() : FrameTransformPair{ 0.0 } {}
	inline FrameTransformPair(double frame) : Frame{ frame } {}
	inline FrameTransformPair(double frame, T transform) : Frame{ frame }, Transform{ transform } {}

	inline bool operator<(const FrameTransformPair& other) { return Frame < other.Frame; }
};

template<typename T>
inline std::pair<FrameTransformPair<T>, FrameTransformPair<T>> GetRangeFromFrame(const std::vector<FrameTransformPair<T>>& transformKeys, const double frame);

#if USE_TEMPLATE_FOR_KEYS
template<typename T>
inline T GetTransformationAt(const std::vector<FrameTransformPair<T>>& transformKeys, double frame);
#endif

class Sequencer : public IDrawable
{
	IActor& m_Actor;
	std::vector<FrameTransformPair<Translation2D>> m_TranslationKeys;
	std::vector<FrameTransformPair<Rotation2D>> m_RotationKeys;
	std::vector<FrameTransformPair<Scale2D>> m_ScaleKeys;
	std::vector<FrameTransformPair<Color>> m_ColorKeys;
	double m_CurrentFrame;

public:
	Sequencer(IActor& sequencingActor);
	Sequencer(const Sequencer& other) = delete;

	void SetTranslationKey(double frame, const Translation2D& translation);
	void SetRotationKey(double frame, const Rotation2D& rotation);
	void SetScaleKey(double frame, const Scale2D& scale);
	void SetColorKey(double frame, const Color& color);

	Translation2D GetTranslationAt(double frame) const;
	Rotation2D GetRotationAt(double frame) const;
	Scale2D GetScaleAt(double frame) const;
	Color GetColorAt(double frame) const;

	void SortTranslationKeys();
	void SortRotationKeys();
	void SortScaleKeys();
	void SortColorKeys();
	void SortAllKeys();

	void SetCurrentFrame(double frame);
	inline double GetCurrentFrame() const { return m_CurrentFrame; }

	virtual void Draw(Image& image) const override;
};

template<typename T>
inline std::pair<FrameTransformPair<T>, FrameTransformPair<T>> GetRangeFromFrame(const std::vector<FrameTransformPair<T>>& transformKeys, const double frame)
{
	if (frame <= transformKeys[0].Frame)
	{
		return { transformKeys[0], transformKeys[0] };
	}
	else if (size_t lastIndex = transformKeys.size() - 1; frame >= transformKeys[lastIndex].Frame)
	{
		return { transformKeys[lastIndex] , transformKeys[lastIndex] };
	}
	else
	{
		for (size_t i = 1u; i < transformKeys.size(); i++)
		{
			if (DoubleEq(transformKeys[i].Frame, frame))
				return { transformKeys[i], transformKeys[i] };
			else if (transformKeys[i].Frame > frame)
				return { transformKeys[i - 1], transformKeys[i] };
		}
	}
	size_t lastIndex = transformKeys.size() - 1;
	return { transformKeys[lastIndex] , transformKeys[lastIndex] };
}

#if USE_TEMPLATE_FOR_KEYS
template<typename T>
inline T GetTransformationAt(const std::vector<FrameTransformPair<T>>& transformKeys, double frame)
{
	const auto& [leftEntry, rightEntry] = GetRangeFromFrame(transformKeys, frame);
	if (DoubleEq(leftEntry.Frame, rightEntry.Frame))
	{
		return leftEntry.Transform;
	}
	else
	{
		double ratio = (frame - leftEntry.Frame) / (rightEntry.Frame - leftEntry.Frame);
		return Lerp(leftEntry.Transform, rightEntry.Transform, ratio);
	}
}
#endif