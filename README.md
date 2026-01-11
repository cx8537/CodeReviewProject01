# 코드 리뷰 교육 자료

## 개요

Pn 등급 체계를 활용한 코드 리뷰 실습 교육 자료입니다.

| 항목 | 내용 |
|------|------|
| **목적** | 코드 리뷰 역량 향상, Pn 등급 체계 학습 |
| **대상** | 신입/주니어 개발자, 코드 리뷰 입문자 |
| **소요 시간** | 3~4시간 (풀 코스) |
| **언어** | C++ |

---

## Pn 등급 체계

| 등급 | 의미 | 액션 | 예시 |
|------|------|------|------|
| **P1** | 반드시 수정 | Request changes | 보안 취약점, 크래시, 로직 오류 |
| **P2** | 적극적 고려 | Request changes | 리소스 누수, 에러 처리 누락 |
| **P3** | 가급적 반영 | Comment | 코드 중복, 네이밍, 매직 넘버 |
| **P4** | 문제 없음 | Approve | 모든 기준 충족 |
| **P5** | 사소한 의견 | Approve | 스타일 선호, 선택적 개선 |

---

## 디렉토리 구조

```
Project01/
│
├── README.md                    # 📌 현재 문서
│
├── 📁 기존 코드베이스 (모범 코드) ──────────────────────────
├── include/
│   ├── NetworkManager.h         # 네트워크 통신 클래스
│   ├── Config.h                 # 설정 관리
│   ├── Logger.h                 # 로깅 유틸리티
│   ├── FileUtils.h              # 파일 유틸리티
│   └── GameTypes.h              # 공용 타입, 상수
├── src/
│   ├── NetworkManager.cpp
│   ├── Config.cpp
│   ├── Logger.cpp
│   └── FileUtils.cpp
├── config.ini                   # 설정 파일
│
├── 📁 리뷰 대상 코드 (실습용) ────────────────────────────
├── gameSample.cpp               # P1 - 반드시 수정
├── updateUserProfile.cpp        # P2 - 적극적 고려
├── cacheManager.cpp             # P3 - 가급적 반영
├── achievementTracker.cpp       # P4 - 문제 없음 (모범)
├── leaderboardClient.cpp        # P5 - 사소한 의견
│
└── 📁 docs/ ─────────────────────────────────────────────
    │
    ├── 📋 규칙 문서
    ├── CODING_CONVENTION.md     # 코딩 컨벤션
    └── SFR-9015-FORMAT.md       # 로그 형식 규격
    │
    ├── 📝 정답지 (강사용)
    ├── REVIEW_ANSWER_P1_gameSample.md
    ├── REVIEW_ANSWER_P2_updateUserProfile.md
    ├── REVIEW_ANSWER_P3_cacheManager.md
    ├── REVIEW_ANSWER_P4_achievementTracker.md
    └── REVIEW_ANSWER_P5_leaderboardClient.md
    │
    ├── 📄 학생 워크시트
    ├── STUDENT_WORKSHEET_TEMPLATE.md        # 범용 템플릿
    ├── STUDENT_WORKSHEET_P1_gameSample.md
    ├── STUDENT_WORKSHEET_P2_updateUserProfile.md
    ├── STUDENT_WORKSHEET_P3_cacheManager.md
    ├── STUDENT_WORKSHEET_P4_achievementTracker.md
    └── STUDENT_WORKSHEET_P5_leaderboardClient.md
    │
    └── 📖 강사용 가이드
        └── INSTRUCTOR_GUIDE.md
```

---

## 빠른 시작

### 강사용

1. **[INSTRUCTOR_GUIDE.md](docs/INSTRUCTOR_GUIDE.md)** 읽기
2. 교육 일정 및 시간 배분 확인
3. 학생용 워크시트 배포 준비
4. 정답지는 강사만 보유

### 학생용

1. **[CODING_CONVENTION.md](docs/CODING_CONVENTION.md)** 먼저 읽기
2. **[SFR-9015-FORMAT.md](docs/SFR-9015-FORMAT.md)** 확인
3. `include/` 폴더의 기존 유틸리티 파악
4. 워크시트에 따라 코드 리뷰 수행

---

## 실습 시나리오

### 공통 배경
> 게임 클라이언트 프로젝트에서 다양한 개발자들이 기능을 추가하고 MR을 제출했습니다.
> 여러분은 시니어 개발자로서 이 코드들을 리뷰해야 합니다.

### 실습별 MR 정보

#### P1: gameSample.cpp
```
[SFR-9012] 게임 로그 및 시스템 정보 서버 전송 기능
- 게임 로그는 설치 경로 아래 \log 디렉토리에서 수집
- SFR-9015 규격에 따른 가변길이 데이터
```
**예상 이슈**: 10개 이상 (자체 클래스 생성, 하드코딩, 로직 오류 등)

#### P2: updateUserProfile.cpp
```
[SFR-9020] 사용자 프로필 업데이트 기능
- 프로필 조회 API 호출
- 프로필 수정 후 서버 동기화
- 로컬 캐시 파일 업데이트
```
**예상 이슈**: 10개 내외 (리소스 누수, null 체크, 버퍼 오버플로우 등)

#### P3: cacheManager.cpp
```
[SFR-9025] 게임 에셋 캐시 매니저
- 캐시 저장/조회/삭제 기능
- 캐시 만료 처리
- 캐시 용량 관리
```
**예상 이슈**: 13개 내외 (매직 넘버, 네이밍, 코드 중복 등)

#### P4: achievementTracker.cpp
```
[SFR-9030] 업적 추적 시스템
- 업적 달성 조건 체크
- 업적 달성 시 서버 전송
- 단위 테스트 통과, 통합 테스트 완료
```
**예상 이슈**: 없음 (모범 코드)

#### P5: leaderboardClient.cpp
```
[SFR-9035] 리더보드 클라이언트
- 리더보드 API 호출
- 순위 데이터 파싱, 캐싱 처리
- API 연동 테스트 완료
```
**예상 이슈**: 사소한 의견 4~5개 (const, 함수명, range-based for 등)

---

## 자료 목록

### 규칙 문서
| 문서 | 설명 | 용도 |
|------|------|------|
| [CODING_CONVENTION.md](docs/CODING_CONVENTION.md) | 프로젝트 코딩 규칙 | 리뷰 기준 |
| [SFR-9015-FORMAT.md](docs/SFR-9015-FORMAT.md) | 로그 페이로드 형식 규격 | 규격 준수 확인 |

### 정답지 (강사용)
| 파일 | 등급 | 이슈 수 |
|------|------|---------|
| [REVIEW_ANSWER_P1_gameSample.md](docs/REVIEW_ANSWER_P1_gameSample.md) | P1 | 12 |
| [REVIEW_ANSWER_P2_updateUserProfile.md](docs/REVIEW_ANSWER_P2_updateUserProfile.md) | P2 | 12 |
| [REVIEW_ANSWER_P3_cacheManager.md](docs/REVIEW_ANSWER_P3_cacheManager.md) | P3 | 13 |
| [REVIEW_ANSWER_P4_achievementTracker.md](docs/REVIEW_ANSWER_P4_achievementTracker.md) | P4 | 0 |
| [REVIEW_ANSWER_P5_leaderboardClient.md](docs/REVIEW_ANSWER_P5_leaderboardClient.md) | P5 | 5 |

### 학생 워크시트
| 파일 | 용도 |
|------|------|
| [STUDENT_WORKSHEET_TEMPLATE.md](docs/STUDENT_WORKSHEET_TEMPLATE.md) | 범용 템플릿 |
| [STUDENT_WORKSHEET_P1_gameSample.md](docs/STUDENT_WORKSHEET_P1_gameSample.md) | P1 실습용 (힌트 포함) |
| [STUDENT_WORKSHEET_P2_updateUserProfile.md](docs/STUDENT_WORKSHEET_P2_updateUserProfile.md) | P2 실습용 |
| [STUDENT_WORKSHEET_P3_cacheManager.md](docs/STUDENT_WORKSHEET_P3_cacheManager.md) | P3 실습용 |
| [STUDENT_WORKSHEET_P4_achievementTracker.md](docs/STUDENT_WORKSHEET_P4_achievementTracker.md) | P4 분석용 |
| [STUDENT_WORKSHEET_P5_leaderboardClient.md](docs/STUDENT_WORKSHEET_P5_leaderboardClient.md) | P5 연습용 |

### 강사용
| 파일 | 설명 |
|------|------|
| [INSTRUCTOR_GUIDE.md](docs/INSTRUCTOR_GUIDE.md) | 진행 가이드, 시간 배분, 디브리핑 포인트 |

---

## 교육 진행 흐름

```
┌─────────────────────────────────────────────────────────────┐
│  1. 도입 (20분)                                              │
│     - Pn 등급 체계 설명                                      │
│     - 코드 리뷰 중요성                                       │
└─────────────────────────────────────────────────────────────┘
                              ↓
┌─────────────────────────────────────────────────────────────┐
│  2. 환경 소개 (15분)                                         │
│     - 기존 코드베이스 (include/, src/)                       │
│     - CODING_CONVENTION.md, SFR-9015-FORMAT.md              │
└─────────────────────────────────────────────────────────────┘
                              ↓
┌─────────────────────────────────────────────────────────────┐
│  3. P1 실습 (55분)                                           │
│     - gameSample.cpp 리뷰                                    │
│     - 워크시트 작성 → 디브리핑                               │
└─────────────────────────────────────────────────────────────┘
                              ↓
┌─────────────────────────────────────────────────────────────┐
│  4. P2 실습 (45분)                                           │
│     - updateUserProfile.cpp 리뷰                             │
│     - P1과 비교 토론                                         │
└─────────────────────────────────────────────────────────────┘
                              ↓
┌─────────────────────────────────────────────────────────────┐
│  5. P3 실습 (35분)                                           │
│     - cacheManager.cpp 리뷰                                  │
│     - "동작하지만 개선 필요" 이해                            │
└─────────────────────────────────────────────────────────────┘
                              ↓
┌─────────────────────────────────────────────────────────────┐
│  6. P4/P5 분석 (40분)                                        │
│     - achievementTracker.cpp: 모범 사례 분석                 │
│     - leaderboardClient.cpp: 사소한 의견 연습                │
└─────────────────────────────────────────────────────────────┘
                              ↓
┌─────────────────────────────────────────────────────────────┐
│  7. 마무리 (20분)                                            │
│     - 전체 정리, Q&A                                         │
│     - 실무 적용 팁                                           │
└─────────────────────────────────────────────────────────────┘
```

---

## 학습 목표

교육 완료 후 학습자는 다음을 할 수 있어야 합니다:

- [ ] Pn 등급(P1~P5)의 차이를 설명할 수 있다
- [ ] 코드에서 P1/P2/P3 수준의 이슈를 식별할 수 있다
- [ ] 기존 코드베이스와 컨벤션을 기준으로 리뷰할 수 있다
- [ ] 건설적인 리뷰 코멘트를 작성할 수 있다
- [ ] MR 설명과 코드의 일치 여부를 확인할 수 있다

---

## 핵심 메시지

> **P1**: "머지하면 장애가 발생할 수 있습니다"

> **P2**: "지금은 동작하지만, 예외 상황에서 문제가 생깁니다"

> **P3**: "동작하지만, 미래의 나/팀에게 빚을 지는 코드입니다"

> **P4**: "잘 작성되었습니다. 승인합니다"

> **P5**: "좋은 코드입니다. 참고할 의견을 남깁니다"

---

## 라이선스

이 교육 자료는 내부 교육 목적으로 자유롭게 사용할 수 있습니다.

---

## 문의

교육 자료 관련 문의는 담당자에게 연락하세요.
